#include <stdio.h>

int main(){
	double integral(double, double, int, double(*fp)(double));
	double formula(double);

	double answer = integral(0,2,20,formula);

	printf("The value of the integral is: %.3lf\n",answer);
	return 0;
}

double integral(double a, double b, int n, double (*fp)(double)){
	double h, sum;
	h = (b - a)/n;
	sum = ((*fp)(a) + (*fp)(b))/2.0;
	for(int i = 1; i < n; i++)
		sum += (*fp)(a + i*h);
	return h * sum;
}

double formula(double x){
	return (x * x) + (x * 5.0) + 3.0;
}