#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

double h(double x)
{
	return log(x) - 4 * x + 7;
}

int main()
{
	double x = 1.9, e = 0.0001;
	double x_old;
	double x_new;
	x_old = x;
	x_new = h(x_old);
	while (abs(x_new - x_old) > e)
	{
		x_old = x_new;
		x_new = h(x_old);
	}
	cout<<x_new<<endl;
	system("pause");
}

