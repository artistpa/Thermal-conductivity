class Solver2d {
protected:
    float t = 1;
    float h = 50;
    float a = 50;
    float T[50][50];
    float Tmax = 5000;
    float Tmin = 300;
public:
    void set_T0(float t, float t_left, float t_right);
    void update_T();
    float get_T(int i, int j);
};
