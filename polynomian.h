#ifndef POLYNOMIAN_H
#define POLYNOMIAN_H

#include <vector>

using namespace std;

class Polynomian {
public:
    static int Degree(const vector<double>& coefficients);

    static vector<double> Add(const vector<double>& poly1, const vector<double>& poly2);

    static vector<double> Subtract(const vector<double>& poly1, const vector<double>& poly2);

    static vector<double> Multiply(const vector<double>& poly1, const vector<double>& poly2);

    static vector<double> LagrangeInterpolation(const vector<double>& x, const vector<double>& y, int n, double xValue);
};

#endif
