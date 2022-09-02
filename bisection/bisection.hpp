#include <iostream>
#include <cmath>

class Bisection {
    private:
        double x;
    public:
        virtual double func(double x) = 0;
        virtual double dfunc(double x) = 0;
        double calc(double x_init, double eps, bool debug_num = false){
            x = x_init;
            while (fabs(x_init - x) <= eps) {
                double funcx = func(x);
                double dfuncx = dfunc(x);
                x_init = x - (funcx / dfuncx);
                if (debug_num) {
                    std::cout << x << " " << x_init << " " << abs(x_init - x) << std::endl;
                }
            }
            return x_init;
        };
};
