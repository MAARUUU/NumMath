#include "pch.h"
#include <iostream>  
#include <iomanip>  

using namespace std;

int main()
{
	const int n = 5;
	const float a[n][n + 1] = { {0.95, 0.31, -0.51, -0.19, 0.41, 0.41},
	{-0.66, 0.98, -0.35, -0.37, -0.69, -0.5},
	{-0.33, 0.7, -0.71, -0.7, 0.26, -0.09},
	{0.91, -0.79, -0.65, 0.85, 0.46, -0.89},
	{-0.72, 0.74, -0.67, 0.67, 0.13, 0.7} };
	const float c[n] = { 0.41, -0.5, -0.09, -0.89, 0.7 };
	float b[n][n] = { {0,0,0,0,0},
					 {0,0,0,0,0},
					 {0,0,0,0,0},
					 {0,0,0,0,0},
					 {0,0,0,0,0} };
	float t[n][n] = { {1,0,0,0,0},
					 {0,1,0,0,0},
					 {0,0,1,0,0},
					 {0,0,0,1,0},
					 {0,0,0,0,1} };
	float y[n] = { 0,0,0,0,0 };
	float x[n] = { 0,0,0,0,0 };

	cout << endl << "Matrix :" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n + 1; j++) {
			if (a[i][j] > 0 && j != 0 && j != n) cout << "+";
			if (j != n)
				cout << setprecision(2) << a[i][j] << "*X" << j + 1;
			else cout << setprecision(2) << "=" << a[i][j];
		}
		cout << endl;
	}

	for (int i = 0; i < n; i++)
	{
		b[i][0] = a[i][0];
		t[0][i] = a[0][i] / b[0][0];
	}

	for (int k = 1; k < n; k++)
	{
		for (int i = k; i < n; i++)
		{
			float s = 0;
			for (int m = 0; m < k; m++)
				s += b[i][m] * t[m][k];
			b[i][k] = a[i][k] - s;
		}
		for (int j = k + 1; j < n; j++)
		{
			float s = 0;
			for (int m = 0; m < k; m++)
				s += b[k][m] * t[m][j];
			t[k][j] = (a[k][j] - s) / b[k][k];
		}
	}

	cout << endl << "Matrix 'B':" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setprecision(2) << setw(7) << b[i][j];
		cout << endl;
	}
	cout << endl << "Matrix 'T':" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setprecision(2) << setw(7) << t[i][j];
		cout << endl;
	}

	y[0] = c[0] / b[0][0];
	for (int i = 1; i < n; i++)
	{
		float s = 0;
		for (int m = 0; m < i; m++)
			s += b[i][m] * y[m];
		y[i] = (c[i] - s) / b[i][i];
	}
	cout << endl << "Vector 'Y':" << endl;
	for (int i = 0; i < n; i++)
		cout << setprecision(2) << setw(7) << y[i];
	cout << endl;

	x[n - 1] = y[n - 1];
	for (int i = n - 1; i > -1; i--)
	{
		float s = 0;
		for (int m = i + 1; m < n; m++)
			s += t[i][m] * x[m];
		x[i] = y[i] - s;
	}
	cout << endl << "Vector 'X':" << endl;
	for (int i = 0; i < n; i++)
		cout << setprecision(2) << setw(7) << x[i];
	cout << endl;

	cin.get();
	return 0;
}
