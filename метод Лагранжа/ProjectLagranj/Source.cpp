#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <conio.h>

float S, chis, znam, x1;
int i, j, k;
float x[6] = { -1.1, -0.2, 0.1, 1.5, 2, 2.6};
float y[6] = { 1.66419,-2.94912, 1.94271, 29.53125, 24, 6.88896 };

int main()
{
	x1 = -0.8;
	S = 0;
	for (k = 0; k < 6; k++)
	{
		chis = 1;

		for (i = 0; i < 6; i++)
		{
			if (i != k)
				chis = chis * (x1 - x[k]);
			
		}
		znam = 1;
		for (j = 0; j < 6; j++)
		{
			if (j != k)
				znam = znam * (x[j] - x[k]);
		}
	
     S = S + (y[k] *( chis / znam));

	}
    
	
	printf("Lagranj = %f ", S);
	system("pause");
}