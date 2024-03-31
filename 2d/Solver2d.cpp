#include "Solver2d.hpp"

void Solver2d::set_T0(float t, float t_left, float t_right){
    /*T[0][0] = t_left;
    T[49][49] = t_right;
    T[0][1] = t_left;
    T[1][0] = t_left;
    T[1][1] = t_left;*/
    for (int i = 0; i < 50; i++)
        T[i][0] = t_left;
    for (int j = 1; j < 50; j++)
        T[0][j] = t_left;
    for (int i = 1; i < 50; i++)
        T[i][49] = t_left;
    for (int j = 1; j < 49; j++)
        T[49][j] = t_left;
    for (int i = 1; i < 49; i++)
        for (int j = 1; j < 49; j++)
                T[i][j] = t;
}


void Solver2d::update_T(){
    float T1[50][50];
    for (int i = 0; i < 50; i++)
        for (int j = 0; j < 50; j++)
            T1[i][j] = this->T[i][j];
    for (int i = 1; i < 49; i++)
        for (int j = 1; j < 49; j++)
            if (T[i][j] <= Tmax)
                this->T[i][j] += ((a * t) / (h * h)) * (T1[i + 1][j] + T1[i - 1][j] + T1[i][j-1] + T1[i][j + 1] - 4 * T1[i][j]);
}


float Solver2d::get_T(int i, int j){
    return T[i][j];
}
