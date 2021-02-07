#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

#include "Polynoms.h"

using namespace std;

double calculatePolynom1(double x, int i)
{
    double z, y, x2, t;
    t = abs(x);
    x2 = x * x;
    y = fma(Poly[i][7], x2, Poly[i][5]);
    y = fma(y, x2, Poly[i][3]);
    y = fma(y, x2, Poly[i][1]);
    z = fma(Poly[i][6], x2, Poly[i][4]);
    z = fma(z, x2, Poly[i][2]);
    z = fma(z, x2, Poly[i][0]);
    y = fma(y, t, z);
    y = copysign(y, x);
    return y;
}
double calculatePolynom2(double x, int i)
{
    double z, y, x2, t;
    t = abs(x);
    x2 = x * x;
    y = fma(Poly[i][9], x2, Poly[i][7]);
    y = fma(y, x2, Poly[i][5]);
    y = fma(y, x2, Poly[i][3]);
    y = fma(y, x2, Poly[i][1]);
    z = fma(Poly[i][8], x2, Poly[i][6]);
    z = fma(z, x2, Poly[i][4]);
    z = fma(z, x2, Poly[i][2]);
    z = fma(z, x2, Poly[i][0]);
    y = fma(y, t, z);
    y = copysign(y, x);
    return y;
}
double myAtanV2(double x) {
    double t;
    t = abs(x);
    int a = round(t * 8 - 0.500001);
    if (a >= 6)
        return calculatePolynom1(x, a);
    else if (a >= 4)
        return calculatePolynom2(x, a);
    else if (a == 3) {
        double y;
        double x2 = t * t;
        y = fma(Poly[3][6], x2, Poly[3][5]);
        y = fma(y, x2, Poly[3][4]);
        y = fma(y, x2, Poly[3][3]);
        y = fma(y, x2, Poly[3][2]);
        y = fma(y, x2, Poly[3][1]);
        y = fma(y, x2, Poly[3][0]);
        y = y * x;
        return y;
    }
    else if (a == 2) {
        double y;
        double x2 = t * t;
        y = fma(Poly[2][5], x2, Poly[2][4]);
        y = fma(y, x2, Poly[2][3]);
        y = fma(y, x2, Poly[2][2]);
        y = fma(y, x2, Poly[2][1]);
        y = fma(y, x2, Poly[2][0]);
        y = y * x;
        return y;
    }
    else {
        double y;
        double x2 = t * t;
        y = fma(Poly[a][4], x2, Poly[a][3]);
        y = fma(y, x2, Poly[a][2]);
        y = fma(y, x2, Poly[a][1]);
        y = fma(y, x2, Poly[a][0]);
        y = y * x;
        return y;
    }

}


int main() {

    
    return 0;
}

