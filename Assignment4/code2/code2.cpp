#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
using namespace std;

double f(double x1, double x2) {
	return exp(x1 + 3 * x2 - 0.1) + exp(x1 - 3 * x2 - 0.1) + exp(-x1 - 0.1);
}
double f_x1_partialDerivative(double x1, double x2) {
	return exp(x1 + 3 * x2 - 0.1) + exp(x1 - 3 * x2 - 0.1) - exp(-x1 - 0.1);
}
double f_x2_partialDerivative(double x1, double x2) {
	return 3 * exp(x1 + 3 * x2 - 0.1) - 3 * exp(x1 - 3 * x2 - 0.1);
}
int main() {
	double x1 = 0.0, x2 = 0.0;//初始点位位于(0,0)
	double a, b;
	double f_now, f_last;
	double t = 0.00001;
	f_now = f(x1, x2);
	f_last = f_now + 1.0;//f_last只需要与f_now不同能启动while循环即可
	while (fabs(f_now - f_last) > 1e-10) {
		double gradient_x1 = f_x1_partialDerivative(x1, x2);
		double gradient_x2 = f_x2_partialDerivative(x1, x2);
		x1 = x1 - t * gradient_x1;
		x2 = x2 - t * gradient_x2;
		f_last = f_now;
		f_now = f(x1, x2);
	}
	cout << "f* = " << setiosflags(ios::fixed) << setprecision(10) << f_now << endl;
	cout << "x1*= " << x1 << endl;
	cout << "x2*= " << x2 << endl;

	return 0;
}
/*
t=0.000000001
fabs(f_now - f_last) > 1e-10
f* = 2.5787295715
x1*= -0.2233238895
x2*= 0.0000000000
*/
