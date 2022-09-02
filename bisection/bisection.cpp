#include <iostream>
#include <cmath>
#include "bisection.hpp"


class BisectionMain: public Bisection {
    private:
    public:
        double func(double x) {
            return 2 * pow(x, 4) + 4 * pow(x, 3) - 3 * pow(x, 2) - x + cos(x) + 11;
        }
        double dfunc(double x) {
            return 8 * pow(x, 3) + 12 * pow(x, 2) - 6 * x - 1 + sin(x);
        }
};


int main() {

    double x1, e, x_upd;

    std::cout.precision(4);
	std::cout.setf(std::ios::fixed);
	std::cout << "First Try: \n";
	std::cin >> x1;
	std::cout << "Accuracy: \n";
	std::cin >> e;

    BisectionMain *bisCalc = new BisectionMain();
    x_upd = bisCalc->calc(x1, e, true);

	std::cout << "The roots is: \n" << x_upd << std::endl;

    return 0;
}
