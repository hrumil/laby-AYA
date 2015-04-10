/*
Вариант № 4
Разработать функцию для вычисления среднего геометрического элементов одномерного массива 
вещественных чисел размерности n. С использованием данной функции для матрицы размерности n х m 
(n и m вводится с клавиатуры, элементы матрицы заполняются с помощью генератора псевдослучайных 
чисел, обеспечить, чтобы дробная часть элементов не была равна 0) получить вектор, содержащий 
средние геометрические строк матрицы. Вывести на печать исходную матрицу и полученный вектор.
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale>
#include <conio.h>
#include <ctime>
#include <math.h>
double *sredgeom(double **p, int n, int m)				// Задаем функцию
{
	double *srg = (double*)malloc(n*sizeof(int));
	for(int i=0; i<n; i++) 
		{
			srg[i]=1;
		}
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
		srg[i]*=p[i][j];								// Считаем произведение
		}
	srg[i]=pow(srg[i],1.0/m);							// Извлекаем корень
	}
	return srg;
}
	
void main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int i, j, n, m, x, y;
	double *srg, **p;
	printf("Введите число n: "); 
	scanf("%d", &n);
	printf("Введите число m: "); 
	scanf("%d", &m);
	
	if(n>0 && m>0)			
	{	
		p=(double**)malloc(n*sizeof(int));
		for(i=0; i<m; i++)		p[i]=(double*)malloc(m*sizeof(int));
		for(i=0; i<n; i++)								
		{
			for(j=0; j<m; j++)
			{											// Избавляемся от нулей в дробной части
				x=rand()%100;							// Целая часть
				y=rand()%100;							// Дробная часть
				p[i][j]=x+0.01*y;						// Заполняем массив
			}
		}	
		for(i=0; i<n; i++)
		{
			for(j=0; j<m; j++)
				{
					printf("%.4g  ", p[i][j]);			// Выводим массив, округляя числа до 4 цифр
				}
			printf("\n");
		}
	
		srg = sredgeom(p, n, m);						// Вызываем функцию
		printf("Полученный вектор:\n");					
		for(int i=0; i<n; i++)	
		{
			printf("%.4g ", srg[i]);					// Выводим вектор, округляя числа до 4 цифр
		}
	}
	_getch();
}