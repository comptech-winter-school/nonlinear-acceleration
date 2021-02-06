#pragma once
#include <fstream>
#include <cmath>
#include <cstdio>
using namespace std;

#include "constants_7deg.h"
#include "Constants_14deg.h"

double coef = intervals /interval;

double Poly(double x, int k){
	double result = 0.0;
	result = A[k][0] + x *(A[k][1] + x * (A[k][2] + x * (A[k][3] + x * (A[k][4] + x * (A[k][5] + x * (A[k][6] + x * A[k][7]))))));
	return result;
}

double Erf(double x){
	int k = 0;
	double result = 0;
	if(abs(x) > interval){
		if(x > 0) return 1.0;    //Для x > 6 (примерно) значение функции 1
		else return -1.0;
	}
	else if(x < 0 && x > -interval ) {
		k = coef * (-x) - 0.5;
		result = -Poly(-x, k);
	}
	else if(x >0 && x < interval) {
		k = coef * x - 0.5;
		result = Poly(x, k);
	}
	return result;
}
