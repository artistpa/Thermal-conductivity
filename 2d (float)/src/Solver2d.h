class Solver2d {
protected:
    float t;
    float h;
    float a;
public:
    void setsolver(float t_, float h_, float a_);
    float operator()(float T1, float T2, float T3, float T4, float T5);
};
