#include "solver.h"

void Solver::set_T0(float t, float t_left, float t_right){
    T[0] = t_left;
    T[99] = t_right;
    for (int i = 1; i < 99; i++)
        T[i] = t;
}
void Solver::update_T(){
    float T1[100];
    for (int i = 0; i < 100; i++)
        T1[i] = this->T[i];
    for (int i = 1; i < 99; i++)
        if (T[i] <= Tmax)
        this->T[i] += ((a * t) / (h * h)) * (T1[i - 1] + T1[i + 1] - 2 * T[i]);
}
float Solver::get_T(int id){
    return T[id];
}

