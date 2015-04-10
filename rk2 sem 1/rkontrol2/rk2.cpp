/*
������� � 4
����������� ������� ��� ���������� �������� ��������������� ��������� ����������� ������� 
������������ ����� ����������� n. � �������������� ������ ������� ��� ������� ����������� n � m 
(n � m �������� � ����������, �������� ������� ����������� � ������� ���������� ��������������� 
�����, ����������, ����� ������� ����� ��������� �� ���� ����� 0) �������� ������, ���������� 
������� �������������� ����� �������. ������� �� ������ �������� ������� � ���������� ������.
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale>
#include <conio.h>
#include <ctime>
#include <math.h>
double *sredgeom(double **p, int n, int m)				// ������ �������
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
		srg[i]*=p[i][j];								// ������� ������������
		}
	srg[i]=pow(srg[i],1.0/m);							// ��������� ������
	}
	return srg;
}
	
void main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int i, j, n, m, x, y;
	double *srg, **p;
	printf("������� ����� n: "); 
	scanf("%d", &n);
	printf("������� ����� m: "); 
	scanf("%d", &m);
	
	if(n>0 && m>0)			
	{	
		p=(double**)malloc(n*sizeof(int));
		for(i=0; i<m; i++)		p[i]=(double*)malloc(m*sizeof(int));
		for(i=0; i<n; i++)								
		{
			for(j=0; j<m; j++)
			{											// ����������� �� ����� � ������� �����
				x=rand()%100;							// ����� �����
				y=rand()%100;							// ������� �����
				p[i][j]=x+0.01*y;						// ��������� ������
			}
		}	
		for(i=0; i<n; i++)
		{
			for(j=0; j<m; j++)
				{
					printf("%.4g  ", p[i][j]);			// ������� ������, �������� ����� �� 4 ����
				}
			printf("\n");
		}
	
		srg = sredgeom(p, n, m);						// �������� �������
		printf("���������� ������:\n");					
		for(int i=0; i<n; i++)	
		{
			printf("%.4g ", srg[i]);					// ������� ������, �������� ����� �� 4 ����
		}
	}
	_getch();
}