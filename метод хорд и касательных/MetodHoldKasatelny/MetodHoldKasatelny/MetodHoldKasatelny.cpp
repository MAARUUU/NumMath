#include "pch.h"
#include <iostream>
#include <math.h>

using namespace std;
double f(double x)
{
	return 6 * x + pow(2, x) + 1;
}
double df(double x)
{
	return  6 + pow(2, x)*log(2);
}

double ddf(double x)
{
	return  pow(2, x)*pow(log(2), 2);
}

int main()
{
	setlocale(0, "RUS");
	unsigned k=0;
	double a = -1, b = 0, e = 0.0001;
	double d;
	double c;
	while (b - a > 2 * e)
	{
		if (f(a)*ddf(a) > 0)
		{
			d = a - f(a) / df(a);
			c = (a*f(b) - b * f(a)) / (f(b) - f(a));
			a = d;
			b = c;
		}
		else
			if (f(b)*ddf(b) > 0)
			{
				d = b - f(b) / df(b);
				c = (a*f(b) - b * f(a)) / (f(b) - f(a));
				b = d;
				a = c;
			}
		k++;
	}
	cout << "x = " << (a + b) / 2 << endl;
	cout << "Количество итераций: " << k << endl;
	system("pause");
}
