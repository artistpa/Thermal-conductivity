#include "Solver2d.h"
#include "iostream"
void Solver2d::setsolver(float t, float h, float a, cont cur, float eps) {
    this->t = t;
    this->h = h;
    this->a = a;
    this->eps=eps;
    this->cur=cur;
    if (this->prom.get_xsize()!=this->cur.get_xsize() || this->prom.get_ysize()!=this->cur.get_ysize())
    {
        std::cout<<this->prom.get_xsize()<<' '<<this->cur.get_xsize() <<' '<<
         this->prom.get_ysize()<<' '<<this->cur.get_ysize()<<"reinit\n";
        this->prom.clear();
        this->prom=cont(cur.get_xsize(),cur.get_ysize());
        for (int i=0;i<6;i++)
            {
                this->delts[i].clear();
                this->delts[i]=cont(cur.get_xsize(),cur.get_ysize());
            }
    }
    //std::cout<<"init end\n";
    //std::cout<<prom.get_xsize()<<' '<<prom.get_ysize()<<'\n';
}

void Solver2d::PrepareMesh(int it)
{
    for (int i = 0; i < cur.get_xsize(); i++)
		for (int j = 0; j < cur.get_ysize(); j++)
        {
            //std::cout<<i<<' '<<j<<"put 1\n";
            this->prom.set_temp_cont(i, j, this->cur.get_el(i, j).get_cell_temp());
            //std::cout<<i<<' '<<j<<"put 2\n";
            for (int k=0;k<it;k++)
                this->prom.set_temp_cont(i, j, this->prom.get_el(i, j).get_cell_temp()+Matrixes::RK45B[it][k]*this->delts[k].get_el(i,j).get_cell_temp());
            //std::cout<<i<<' '<<j<<"put 3\n";
        }
}
void Solver2d::doStep(int it)
{
    int n=0;
    PrepareMesh(it);
    //#pragma omp parallel for 
    for (int i = 1; i < cur.get_xsize()-1; i++)
        //#pragma omp parallel for 
		for (int j = 1; j < cur.get_ysize()-1; j++)
        {
            n=0;
            float T1=this->prom.get_el(i, j).get_cell_temp(),T2=0,T3=0,T4=0,T5=0;
            if (j-1>=0)
            {
                n++;
                T2=this->prom.get_el(i, j-1).get_cell_temp();
            }
            if (j + 1 < cur.get_xsize())
            {
                n++;
                T3=this->prom.get_el(i, j+1).get_cell_temp();
            }
            if (i + 1 < cur.get_ysize())
            {
                n++;
                T4=this->prom.get_el(i+1, j).get_cell_temp();
            }
            if (i-1>=0)
            {
                n++;
                T5=this->prom.get_el(i-1, j).get_cell_temp();
            }
			this->delts[it].set_temp_cont(i, j, ((a * t) / (h * h)) * (T2 + T3 + T4 + T5 - n * T1));
        }
}

void Solver2d::finalise(int n, unsigned solver)
{
    for (int k=0;k<n;k++)
    //#pragma omp parallel for 
        for (int i = 1; i < cur.get_xsize()-1; i++)
        //#pragma omp parallel for 
		    for (int j = 1; j < cur.get_ysize()-1; j++)
                this->cur.set_temp_cont(i, j, this->cur.get_el(i, j).get_cell_temp()+(Matrixes::FCH[solver])[k]*this->delts[k].get_el(i,j).get_cell_temp());
}

cont Solver2d::operator() (unsigned solver) {
    switch (solver)
    {
    case Solvers::EULER:
        doStep(0);
        finalise(1,Solvers::EULER);
        break;
    case Solvers::RK4:
        for (int i=0;i<6;i++)
            doStep(i);
        finalise(6,Solvers::RK4); 
        break;
    default:
        finalise(0,Solvers::EULER);
        break;
    }
    return  this->cur;
}

