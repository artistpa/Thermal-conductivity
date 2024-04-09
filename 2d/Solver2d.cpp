#include "Solver2d.hpp"

float Solver2d::operator() (float T1, float T2, float T3, float T4, float T5){
    return(T1 + ((a * t) / (h * h)) * (T2 + T3 + T4 + T5 - 4 * T1));
    /*for (int i = 0; i < mesh.get_uysize(); i++)
        for (int j = 0; j < mesh.get_uxsize(); j++)
            T[i][j] = mesh.get_temp(i, j);
    for (int i = 1; i < (mesh.get_uysize() - 1); i++)
        for (int j = 1; j < (mesh.get_uxsize() - 1); j++)
            if (T[i][j] <= this->T_max)
                 mesh.set_temp(i, j, T[i][j] + ((a * t) / (h * h)) * (T[i + 1][j] + T[i - 1][j] + T[i][j-1] + T[i][j + 1] - 4 * T[i][j]));*/
}

