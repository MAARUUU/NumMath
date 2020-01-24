// slu.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;


void main()
{
	setlocale(LC_ALL, "Russian");

	const int size = 5;
	const int acc = 4;


	const int E = 0.001;

	float SLU[size][size + 1] = { {0.95, 0.31, -0.51, -0.19, 0.41, 0.41},
	{-0.66, 0.98, -0.35, -0.37, -0.69, -0.5},
	{-0.33, 0.7, -0.71, -0.7, 0.26, -0.09},
	{0.91, -0.79, -0.65, 0.85, 0.46, -0.89},
	{-0.72, 0.74, -0.67, 0.67, 0.13, 0.7} };

	float B[size], D[size] = { 0.41, -0.5, -0.09, -0.89, 0.7 };

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size + 1; j++) {
			if (SLU[i][j] > 0 && j != 0 && j != size) cout << "+";
			if (j != size)
				cout << setprecision(acc) << SLU[i][j] << "*X" << j + 1;
			else cout << setprecision(acc) << "=" << SLU[i][j];
		}
		cout << "\n";
	}



	cout << "\n";
	cout << "\n";
	cout << "\n";

	//Прямой ход Гаусса.
	cout << "Прямой ход Гаусса\n";
	cout << "\n";
	for (int k = 0; k < size - 1; k++)
	{
		float vedel = SLU[k][k];
		cout << vedel << "\n";

		for (int i = k + 1; i < size; i++)
		{
			float mul = SLU[i][k] / (-vedel);
			cout << mul << " множитель строки\n";


			for (int j = k; j < size + 1; j++) {

				SLU[i][j] += (SLU[k][j] * mul);

				if (SLU[i][j] > 0 && j != 0 && j != size) cout << "+";
				if (j != size)
					cout << setprecision(acc) << SLU[i][j] << "*x" << j + 1;
				else cout << "=" << setprecision(acc) << SLU[i][j];
			}

			cout << "\n";
		}
		cout << "\n";
	}

	cout << "\n";
	cout << "\n";
	cout << "\n";

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size + 1; j++) {
			if (SLU[i][j] > 0 && j != 0 && j != size) cout << "+";
			if (j != size)
				cout << setprecision(acc) << SLU[i][j] << "*X" << j + 1;
			else cout << setprecision(acc) << "=" << SLU[i][j];
		}
		cout << "\n";
	}

	cout << "\n";
	cout << "\n";
	cout << "\n";


	//Обратный ход Гаусса.
	cout << "Обратный ход Гаусса\n";
	cout << "\n";
	for (int k = size - 1; k > 0; k--)
	{
		float vedel = SLU[k][k];
		cout << vedel << "\n";

		for (int i = 0; i <
			k; i++)
		{
			float mul = SLU[i][k] / (-vedel);
			cout << mul << " множитель столбца\n";

			for (int j = size; j >= 0; j--) {

				SLU[i][j] += (SLU[k][j] * mul);

				cout << setprecision(acc) << SLU[i][j] << "*x" << j + 1 << "  ";

			}

			cout << "\n";
		}
		cout << "\n";
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size + 1; j++) {
			if (SLU[i][j] > 0 && j != 0 && j != size) cout << "+";
			if (j != size)
				cout << setprecision(acc) << SLU[i][j] << "*X" << j + 1;
			else cout << setprecision(acc) << "=" << SLU[i][j];
		}
		cout << "\n";
	}

	cout << "\n";
	cout << "\n";
	cout << "\n";


	for (int i = 0; i < size; i++)
	{
		B[i] = SLU[i][size] / SLU[i][i];
		cout << setprecision(acc) << "X" << i << "=" << B[i] << "\n";
	}

	// метод невязок
	for (int i = 0; i < size; i++) {
		float c = 0;
		for (int j = 0; j < size; j++) {
			if (j = size - 1) {
				c = c + SLU[i][j];
			}
			else c = c - (B[i] * SLU[i][j]);
		}

		if (D[i] - c < E) {
			cout << i + 1 << " верно\n";
		}
		else
		{
			cout<<i - 1<<" не верно\n";
		}
	}
}