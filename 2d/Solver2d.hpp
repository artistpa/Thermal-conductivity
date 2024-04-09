#pragma once
#include <vector>
class Solver2d {
protected:
    const float t = 1;
    const float h = 50;
    const float a = 50;
public:
    float operator()(float T1, float T2, float T3, float T4, float T5);
};

