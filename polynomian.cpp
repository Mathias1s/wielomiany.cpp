#include "polynomian.h"

using namespace std;

int Polynomian::Degree(const vector<double>& coefficients)
{
    return coefficients.size() - 1;
}

vector<double> Polynomian::Add(const vector<double>& poly1, const vector<double>& poly2)
{
    int n = max(poly1.size(), poly2.size());
    vector<double> result(n, 0.0);

    for (int i = 0; i < poly1.size(); i++)
    {
        result[i] += poly1[i];
    }

    for (int i = 0; i < poly2.size(); i++)
    {
        result[i] += poly2[i];
    }

    return result;
}

vector<double> Polynomian::Subtract(const vector<double>& poly1, const vector<double>& poly2)
{
    int n = max(poly1.size(), poly2.size());
    vector<double> result(n, 0.0);

    for (int i = 0; i < poly1.size(); i++)
    {
        result[i] += poly1[i];
    }

    for (int i = 0; i < poly2.size(); i++)
    {
        result[i] -= poly2[i];
    }

    return result;
}

vector<double> Polynomian::Multiply(const vector<double>& poly1, const vector<double>& poly2)
{
    int n = poly1.size() + poly2.size() - 1;
    std::vector<double> result(n, 0.0);

    for (int i = 0; i < poly1.size(); i++)
    {
        for (int j = 0; j < poly2.size(); j++)
        {
            result[i + j] += poly1[i] * poly2[j];
        }
    }

    return result;
}

std::vector<double> Polynomian::LagrangeInterpolation(const std::vector<double>& x, const std::vector<double>& y, int n, double xValue)
{
    std::vector<double> result(n, 0.0);

    for (int i = 0; i < n; i++)
    {
        double term = 1.0;

        for (int j = 0; j < n; j++)
        {
            if (i != j) {
                term *= (xValue - x[j]) / (x[i] - x[j]);
            }
        }

        result[i] = term * y[i];
    }

    return result;
}
