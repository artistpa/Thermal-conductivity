#include "cont.h"

enum Solvers
{
    EULER,
    RK45,
};


class Matrixes
{
    public:
    inline static const float RK45A[6]={0,2/9., 1/3.,3/4.,1,5/6.};
    inline static const float RK45B[6][5]={
        {},
        {2/9.},
        {1/12.,1/4.},
        {69/128.,-243/128.,135/64.},
        {-17/12.,27/4.,-27/5.,16/15.},
        {65/432.,-5/16.,13/16.,4/27.,5/144.}
    };
    inline static const float RK45CH[6]={47/450.,0,12/25.,32/225.,1/30.,6/25.};
    inline static const float EulerCH[1]={1.};
    inline static const float * const FCH[2]={EulerCH, RK45CH};
};

class Solver2d {
private:
    cont cur, prom;
    cont delts[6];
    void PrepareMesh(int i);
    void doStep(int i);
    void finalise(int n, unsigned solver);
protected:
    float t;
    float h;
    float a;
    float eps;
public:
    void setsolver(float t, float h, float a, cont current, float eps=1e-3);
    cont operator()(unsigned slover=Solvers::EULER);
};
