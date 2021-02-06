#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

#include "Polynoms.h"

using namespace std;

double calculatePolynom(double x, const double* Poly)
{
    double z, y, x2, t;
    t = abs(x);
    x2 = x * x;
    y = fma(Poly[9], x2, Poly[7]);
    y = fma(y, x2, Poly[5]);
    y = fma(y, x2, Poly[3]);
    y = fma(y, x2, Poly[1]);
    z = fma(Poly[8], x2, Poly[6]);
    z = fma(z, x2, Poly[4]);
    z = fma(z, x2, Poly[2]);
    z = fma(z, x2, Poly[0]);
    y = fma(y, t, z);
    y = copysign(y, x);
    return y;
}

double myAtan(double x) {
    double t, x2, y, z;
    t = abs(x);
    x2 = t * t;

    if (t > 1.5) {
        if (t > 5)
            if (t > 8)
                if (t > 11)
                    if (t > 16)
                        return calculatePolynom(x, P20);
                    else
                        return calculatePolynom(x, P19);
                else
                    return calculatePolynom(x, P18);
            else if (t > 6.2)
                return calculatePolynom(x, P17);
            else
                return calculatePolynom(x, P16);
        else if (t > 2.5)
            if (t > 4)
                return calculatePolynom(x, P15);
            else if (t > 3.2)
                return calculatePolynom(x, P14);
            else
                return calculatePolynom(x, P13);
        else if (t > 2)
            return calculatePolynom(x, P12);
        else
            return calculatePolynom(x, P11);
    }
    else if (t > 0.5) {
        if (t > 0.75)
            if (t > 1.2)
                return calculatePolynom(x, P10);
            else if (t > 0.95)
                return calculatePolynom(x, P9);
            else
                return calculatePolynom(x, P8);
        else if (t > 0.6)
            return calculatePolynom(x, P7);
        else
            return calculatePolynom(x, P6);
    }
    else if (t > 0.2) {
        if (t > 0.4) {
            y = fma(P5[6], x2, P5[5]);
            y = fma(y, x2, P5[4]);
            y = fma(y, x2, P5[3]);
            y = fma(y, x2, P5[2]);
            y = fma(y, x2, P5[1]);
            y = fma(y, x2, P5[0]);
            y = y * x;
            return y;
        }
        else if (t > 0.3) {
            y = fma(P4[5], x2, P4[4]);
            y = fma(y, x2, P4[3]);
            y = fma(y, x2, P4[2]);
            y = fma(y, x2, P4[1]);
            y = fma(y, x2, P4[0]);
            y = y * x;
            return y;
        }
        else {
            y = fma(P3[5], x2, P3[4]);
            y = fma(y, x2, P3[3]);
            y = fma(y, x2, P3[2]);
            y = fma(y, x2, P3[1]);
            y = fma(y, x2, P3[0]);
            y = y * x;
            return y;
        }
    }
    else if (t > 0.1) {
        y = fma(P[4], x2, P[3]);
        y = fma(y, x2, P[2]);
        y = fma(y, x2, P[1]);
        y = fma(y, x2, P[0]);
        y = y * x;
        return y;
    }
    else {
        y = fma(P[4], x2, P[3]);
        y = fma(y, x2, P[2]);
        y = fma(y, x2, P[1]);
        y = fma(y, x2, P[0]);
        y = y * x;
        return y;
    }
}


int main() {
    double x;
    cin >> x;
    
    cout << endl;

    printf("%.40lf", atan(x) - myAtan(x));
    return 0;
}

