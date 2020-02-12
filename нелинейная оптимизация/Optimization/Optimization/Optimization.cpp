#include <iostream>
#include <cmath>

const float E = 0.001;

using namespace std;

float f(float x)
{
	float ret = sqrt(5 * x*x - x + 1);
	return ret;
}


void metod_Svenna(float &a, float &b, float x0, float d)
{
		float x_L = x0 - d;
		float x_C = x0;
		float x_R = x0 + d;
		while (!(f(x_C) < f(x_L) && f(x_C) < f(x_R)))
		{
			if (f(x_L) > f(x_C) && f(x_C) > f(x_R))
			{
				x_L = x_C;
				x_C = x_R;
				x_R = x_R + 2 * d;
			}
			else if (f(x_L) < f(x_C) && f(x_C) < f(x_R))
			{
				x_R = x_C;
				x_C = x_L;
				x_L = x_L - 2 * d;
			}
			d *= 2;
		}
		a = x_L;
		b = x_R;
}


float metod_passive_search(float a, float b)
{
	/*const int N = 118;
	int i, imin;
	double xPmin, yPmin;
	double x1, x2, y1, y2, x[N + 2], y[N + 2];
	const double d = 0.1;
	int j = 0;
	for (double i = a; i <= b + 2 * ((b - a) / N); i += (b - a) / N)
		x[j++] = i;
	for (int i = 0; i < N + 2; i++)
		y[i] = f(x[i]);
	yPmin = y[1];
	for (i = 1; i < N; i++)
	{
		if (y[i] <= yPmin)
		{
			yPmin = y[i];
			imin = i;
		}
	}
	xPmin = (x[imin - 1] + x[imin + 1]) / 2;
	cout << "X_min =  " << xPmin << endl;
	cout << "f(xmin) = " << f(xPmin) << endl;*/
	float Ymin = f(a), Xmin = 0;
	for (float i = a; i <= b; i = i + E) {
		if (f(i) < Ymin) { //сравним текущее значение функции с новым
			Ymin = f(i);  
			Xmin = i;  
		}
	}
	cout << "X_min =  " << Xmin << endl;
	cout << "f(xmin) = " << f(Xmin) << endl;
	return 0;
}



float metod_Div_Half(float a, float b)
{
	long nIter = 1;
	double  x1,xmin;
	double x2;
	while (E <= fabs(b - a))
	{
		float x1 = (3 * a + b)*0.25,
			  x2 = (a + b)*0.5,
			  x3 = (a + 3 * b)*0.25;

		/*cout << "Iteration : " << (nIter++) << endl;
		cout << "x1 =  " << x1 << endl;
		cout << "x2 =  " << x2 << endl;
		cout << "x3 =  " << x3 << endl;
		cout << "f(x1) " << f(x1) << endl;
		cout << "f(x2) " << f(x2) << endl;
		cout << "f(x3) " << f(x3) << endl;*/

		if (f(x2) < f(x1) && f(x2) < f(x3))
		{
			a = x1;
			b = x3;
		}
		else if (f(x1) > f(x2) && f(x2) > f(x3))
		{
			a = x2;
		}
		else 
			b = x2;
	}
	cout << "X_min =  " << (xmin = (a + b)*0.5) << endl;
	cout << "f(xmin) = " << f(xmin) << endl;
	return 0;
}



float metod_Golden_Ratio( float a,  float b)
{
	long nIter = 1;
	double  xmin;
	double t = (sqrt(5) - 1)*0.5;

	double x1 = t * a + (1 - t)*b;
	double x2 = (1 - t)*a + t * b;
	while (E <= fabs(b - a))
	{
		/*cout << "Iteration : " << (nIter++) << endl;
		cout << "x1 =  " << x1 << endl;
		cout << "x2 =  " << x2 << endl;
		cout << "f(x1) " << f(x1) << endl;
		cout << "f(x2) " << f(x2) << endl;*/
		if (f(x2) < f(x1))
			a = x1;
		else
			b = x2;
		x1 = t * a + (1 - t)*b;
		x2 = (1 - t)*a + t * b;
	}
	cout << "X_min =  " << (xmin = (a + b)*0.5) << endl;
	cout << "f(xmin) =  " << f(xmin) << endl;
	return 0;
}




int main()
{
	setlocale(0, "RUS");

	float a = 0, b = 0;
	metod_Svenna(a, b, 0, 0.01);
	cout <<'['<< a <<','<< b <<']'<< endl;
	cout << "\n";
	cout << "Метод пассивного поиска: " << endl;
	cout << metod_passive_search(a, b) << endl;
	cout << "\n";
	cout << "Метод деления пополам: " << endl;
	cout << metod_Div_Half(a, b) << endl;
	cout << "\n";
	cout << "Метод золотого сечения: " << endl;
	cout << metod_Golden_Ratio(a, b) << endl;
}

