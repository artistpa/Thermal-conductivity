#include "Solver2d.h"

void Solver2d::setsolver(float t_, float h_, float a_) {
    this->t = t_;
    this->h = h_;
    this->a = a_;
}

float Solver2d::operator() (float T1, float T2, float T3, float T4, float T5) {
    return(T1 + ((a * t) / (h * h)) * (T2 + T3 + T4 + T5 - 4 * T1));
}

