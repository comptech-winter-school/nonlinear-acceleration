/*
 * erf_func14.h
 *
 *  Created on: 6 февр. 2021 г.
 *      Author: andre
 */

#ifndef ERF_FUNC14_H_
#define ERF_FUNC14_H_

double coef2 = intervals /interval;


double Poly14(double x, int k){
	double result = 0.0;
	double z = x * x;
	double w = z * x;
	double p1 = B[k][0] + w * (B[k][3] + w * (B[k][6] + w * (B[k][9] + w * B[k][12])));                              //распараллелил поток
	double p2 = B[k][1] + w * (B[k][4] + w * (B[k][7] + w * (B[k][10] + w * B[k][13])));
	double p3 = B[k][2] + w * (B[k][5] + w * (B[k][8] + w * (B[k][11] + w * B[k][14])));
	result = p1 + x*p2 + x*x*p3;
	return result;
}

double Erf14(double x){
	int k = 0;
	double result = 0;
	if(abs(x) > interval){
		if(x > 0) return 1.0;    //Для x > 6  значение функции = 1
		else return -1.0;
	}
	else if(x < 0 && x > -interval ) {
		k = coef2 * (-x)  - 0.5;
		result = -Poly14(-x, k);
	}
	else if(x >0 && x < interval) {
		k = coef2 * x  - 0.5;
		result = Poly14(x, k);
	}
	return result;
}


#endif /* ERF_FUNC14_H_ */
