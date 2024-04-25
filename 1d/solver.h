class Solver {
protected:
    float t = 1;
    float h = 5;
    float a = 1;
    float T[100];
    float Tmax = 10000;
    float Tmin = 100;
public:
    void set_T0(float t, float t_left, float t_right);
    void update_T();
    float get_T(int id);
};
