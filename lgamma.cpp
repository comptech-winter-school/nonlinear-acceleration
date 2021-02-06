#include <math.h>
#include <iostream>
#include <iomanip>
#include <string>
#include "constants.h"
/*
------------Method------------
 1) Special Cases:
    tiny x: lG(x) ~ -log(x)
    lG(1) = lG(2) = 0
    lG(inf) = inf
    lgamma(1)=lgamma(2)=0
    lgamma(0) = lgamma(inf) = inf

 2) 0 < x <= 8
    we reduce x to a number in [1.0,2.0] by
            lgamma(1+s) = log(s) + lgamma(s)

 3) Polynomial approximation of lgamma around its
    minimun [1.23164,1.73163]
            Let z = x-ymin; (ymin = 1.46)
            lgamma(x) = -1.214862905358496078218 + z^2*poly(z)
    where
            poly(z) is a 14 degree polynomial.

 4) For x >= 8, we have
    lgamma(x)~(x-0.5)log(x)-x+0.5*log(2pi)+1/(12x)-1/(360x**3)+....
    (better formula:
       lgamma(x)~(x-0.5)*(log(x)-1)-.5*(log(2pi)-1) + ...)
    Let z = 1/x, then we approximation
            f(z) = lgamma(x) - (x-0.5)(log(x)-1)
    by
                                3       5             11
            w = w0 + w1*z + w2*z  + w3*z  + ... + w6*z
    where
            |w - f(z)| < 2**-58.74

 5) For negative x:
    lgamma(x) = log(pi/(|x*sin(pi*x)|)) - lgamma(-x);
    */

double my_lgamma(double x);
double my_lgamma_neg(double x) {
    return log(pi/(fabs(x*sin(pi*x)))) - my_lgamma(-x);
}

double my_lgamma(double x) {
    static const double abs_x = fabs(x);

    if ((abs_x - epsilon) < zero) return -log(abs_x);       /* tiny x: lG(x) ~ -log(x)  */
    if ((x - 1.0) == zero or (x - 2.0) == zero) return 0;   /* lG(1) = lG(2) = 0        */
    if ((x - two52) >= 0) return abs_x/zero;                /* lG(inf) = inf            */
    if (x < 0) return my_lgamma_neg(x);

    double result = zero;
    double z;

    if ((x > zero) and ((x - 1.0) < zero)) {                         /* (0,1)  */
        result = -log(x);                                            /* reduce x to a number in [1,2]  */
        x += one;                                                    /* lgamma(x) = lgamma(x+1)-log(x) */
    }
    if (((x - 1.0) > zero) and ((x - 1.23164) <= zero)) {            /* [1.0,1.23164]  */
        z = x - one;
        double p1 = z*(u0+z*(u1+z*(u2+z*(u3+z*(u4+z*u5)))));
        double p2 = one+z*(v1+z*(v2+z*(v3+z*(v4+z*v5))));
        return result + (-0.5*z + p1/p2);
    }
    else if (((x - 1.23164) > zero) and ((x - 1.73163) <= zero)) {   /* [1.23164,1.73163] - around minimum */
        z = x - xmin;
        double z2 = z*z;                                             // z^2
        double z3 = z2*z;                                            // z^3
        double p1 = t0+z3*(t3+z3*(t6+z3*(t9 +z3*t12)));              /* |               | */
        double p2 = t1+z3*(t4+z3*(t7+z3*(t10+z3*t13)));              /* | parallel comp | */
        double p3 = t2+z3*(t5+z3*(t8+z3*(t11+z3*t14)));              /* |               | */
        double p =  z2*p1-(tt-z3*(p2+z*p3));                         // poly(z), 14 degree polynomial
        return result + tf + p;                                      // -1.214862905358496078218 + z^2*poly(z)
    }
    else if (((x - 1.7316) >= zero) and ((x - 2.0) <= zero)) {       /* [1.7316,2] - 11 degree polynomial*/
        z = 2.0 - x;
        double z2 = z*z; // z^2
        double p1 = a0+z2*(a2+z2*(a4+z2*(a6+z2*(a8+z2*a10))));
        double p2 = z2*(a1+z2*(a3+z2*(a5+z2*(a7+z2*(a9+z2*a11)))));
        double p  = z*p1+p2;
        return result + p - 0.5*z;
    }

    else if ((x - 8.0) < zero) {
        /* 2.0 < x < 8.0 */
        int i = (int) x;
        double y = x - (double) i;
        double p = y * (s0 + y * (s1 + y * (s2 + y * (s3 + y * (s4 + y * (s5 + y * s6))))));
        double q = one + y * (r1 + y * (r2 + y * (r3 + y * (r4 + y * (r5 + y * r6)))));
        double r = half * y + p / q;
        z = one;    /* lgamma(1+s) = log(s) + lgamma(s) */
        switch (i) {
            case 7:
                z *= (y + 6.0);
            case 6:
                z *= (y + 5.0);
            case 5:
                z *= (y + 4.0);
            case 4:
                z *= (y + 3.0);
            case 3:
                z *= (y + 2.0);
            case 2:
                return r + log(z);
        }
    }
    if ((x - 8.0) == zero) return 8.5251613610654143001655310363471250507596677369368988303241467466;
    if ((x - 8.0) > zero){
        double y = z * z;	// for x >= 8: lgamma(x)~(x-0.5)*(log(x)-1)-.5*(log(2pi)-1) + ...
        double w = w0 + z * (w1 + y * (w2 + y * (w3 + y * (w4 + y * (w5 + y * w6)))));
        return  (x - 0.5)*(log(x) - 1.) +  w;
    }
    return -1;
}
int main(int argc, char *argv[]) {
   double x;
        std::cin >> x;
        std::cout.setf(std::ios::fixed);
        std::cout << std::setprecision(30) << my_lgamma(x) << std::endl;
    return 0;
}

