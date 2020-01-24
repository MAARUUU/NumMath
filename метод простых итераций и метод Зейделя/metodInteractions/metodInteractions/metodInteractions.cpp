#include "pch.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	const int n = 5;
	float a[n][n] = { {30, -3, 7, -2, 7},
	{-1, 30, -8, 4, 6},
	{0, 3, 17, 0, 0},
	{5, 3, 3, 38, 9},
	{8, 5, -9, -8, 45} };


	float c[n] = { 39,62,60,116,41 };
	const float eps = 0.001;

	//Метод простых итераций
	cout << "Метод простых итераций"<<endl;
	float x_old[n] = { 0,0,0,0,0 };
	float x_new[n] = { 0,0,0,0,0 };


	//вычисление X(1)
	int k = 1;
	bool t = true;

	for (int i = 0; i < n; i++) {
		float s = 0;

		for (int j = 0; j < n; j++)
			if (j != i)
				s += x_old[j] * a[i][j];

		x_new[i] = (c[i] - s) / a[i][i];


	}
	cout << "x(" << k << ") = ";
	for (int i = 0; i < n; i++)
		cout << x_new[i] << " ";
	cout << endl;

	//вычисление X(k) с проверкой условия остановки
	while (t) {
		for (int i = 0; i < n; i++) {
			x_old[i] = x_new[i];
		}

		//t = false;

		for (int i = 0; i < n; i++) {
			float s = 0;

			for (int j = 0; j < n; j++)
				if (j != i)
					s += x_old[j] * a[i][j];

			x_new[i] = (c[i] - s) / a[i][i];

			if (fabs(x_new[i] - x_old[i]) <= eps) t = false;
		}
		k = k + 1;
		cout << "x(" << k << ") = ";
		for (int i = 0; i < n; i++)
			cout << x_new[i] << " ";
		cout << endl;
	}
	cout << "Выполнено " << k << " итераций\n" << endl;

	//Метод Зейделя
	cout << "Метод Зейделя"<<endl;
	memset(x_old, 0, n * sizeof(int));
	memset(x_new, 0, n * sizeof(int));

	//вычисление X(1)
	k = 1;
	t = true;
	for (int i = 0; i < n; i++) {
		float s = 0;
		for (int j = 0; j < n; j++) {
			if (j < i)
				s = s + x_new[j] * a[i][j];
			else if (j > i)
				s = s + x_old[j] * a[i][j];
		}
		x_new[i] = (c[i] - s) / a[i][i];
	}
	cout << "x(" << k << ") = ";
	for (int i = 0; i < n; i++)
		cout << x_new[i] << " ";
	cout << endl;

	//вычисление X(k) с проверкой условия остановки
	while (t) {
		for (int i = 0; i < n; i++) {
			x_old[i] = x_new[i];
		}

		for (int i = 0; i < n; i++) {
			float s = 0;
			for (int j = 0; j < n; j++)
				if (j < i)
					s = s + x_new[j] * a[i][j];
				else if (j > i)
					s = s + x_old[j] * a[i][j];
			x_new[i] = (c[i] - s) / a[i][i];


			if (fabs(x_new[i] - x_old[i]) <= eps) t = false;
		}
		k = k + 1;
		cout << "x(" << k << ") = ";
		for (int i = 0; i < n; i++)
			cout << x_new[i] << " ";
		cout << endl;
	}
	cout << "Выполнено " << k << " итераций\n" << endl;
}

