#pragma once

/*
 * Strategia – czynnoœciowy wzorzec projektowy, który definiuje rodzinê
 * wymiennych algorytmów i kapsu³kuje je w postaci klas. Umo¿liwia wymienne
 * stosowanie ka¿dego z nich w trakcie dzia³ania aplikacji niezale¿nie od
 * korzystaj¹cych z nich u¿ytkowników.
*/

#include <iostream>
#include <vector>
#include <complex>
#include <tuple>

using namespace std;

namespace Strategy
{

struct DiscriminantStrategy
{
    virtual double calculate_discriminant(double a, double b, double c) = 0;
};

struct OrdinaryDiscriminantStrategy : DiscriminantStrategy
{
    virtual double calculate_discriminant(double a, double b, double c) override
    {
        return pow(b, 2.0) - 4.0 * a * c;
    }
};

struct RealDiscriminantStrategy : DiscriminantStrategy
{
    virtual double calculate_discriminant(double a, double b, double c) override
    {
        auto d = pow(b, 2.0) - 4.0 * a * c;

        return d < 0 ? numeric_limits<double>::quiet_NaN() : d;
    }
};

class QuadraticEquationSolver
{
    DiscriminantStrategy& strategy;
public:
    QuadraticEquationSolver(DiscriminantStrategy &strategy) : strategy(strategy) {}

    tuple<complex<double>, complex<double>> solve(double a, double b, double c)
    {
        complex<double> d{ strategy.calculate_discriminant(a,b,c), 0 };

        auto x1 = (-b + sqrt(d)) / (2.0 * a);
        auto x2 = (-b - sqrt(d)) / (2.0 * a);

        return make_tuple(x1, x2);
    }
};

} // namespace Strategy
