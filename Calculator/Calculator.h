#pragma once
class Calculator
{
private:
    double result = 0.0;
public:
    enum class Error {
        Success,
        DivisionByZero,
        TwoRoots,
        OneRoot,
        NoRoots,
        LinearFunction,
        ConstansFunction
    };

    Calculator();
    ~Calculator();

    void add(double x, double y);
    void subtract(double x, double y);
    void multiply(double x, double y);
    Error divide(double x, double y);

    double get_result();
    Error square_function_roots(
        double a, double b, double c,
        double& x1, double& x2
    );
};

