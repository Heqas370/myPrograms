#include "Calculator.h"
#include <cmath>

Calculator::Calculator() {}

Calculator::~Calculator() {}

void Calculator::add(double x, double y) {
    result = x + y;
}

void Calculator::subtract(double x, double y) {
    result = x - y;
}

void Calculator::multiply(double x, double y) {
    result = x * y;
}

Calculator::Error Calculator::divide(double x, double y) {
    if (y == 0.0) {
        return Calculator::Error::DivisionByZero;
    }
    result = x / y;
    return Calculator::Error::Success;
}

double Calculator::get_result() {
    return result;
}

Calculator::Error Calculator::square_function_roots(
    double a, double b, double c,
    double& x1, double& x2
) {
    if (a == 0)
        return Calculator::Error::LinearFunction;
    else
    {
        double delta = b * b - (4 * a * c);
        if (delta < 0)
            return Calculator::Error::NoRoots;
        else if (delta==0)
        {
            x1 = -b / 2 * a;
            return Calculator::Error::OneRoot;
        }
        else
        {
            x1 = (-b + sqrt(delta)) / (2 * a);
            x2 = (-b - sqrt(delta)) / (2 * a);
            return Calculator::Error::TwoRoots;
        }
        
    }
    return Calculator::Error::Success;
}
