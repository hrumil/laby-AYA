// ������ - ����� (����: ��� ������, ��������, ������������, ��� �������, ����� �������) 
// ���������� �� �������� ������� ������ (���������) �� �������� �����


/*
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <locale>

using namespace std;

struct book 				// �������� ���������
	{
		char author[64];	// ��� ������
		char title[64];		// �������� �����
		char publ[64];		// ������������
		int year;			// ��� �������
		int str;			// ����� �������
	};

int main(int argc, char* argv[])
{
setlocale(LC_ALL, "Russian");
int n;
printf("������� ����� ����: ");
scanf("%d", &n);
if(n>0)
{
book *a= (book*)malloc(n*sizeof(book));
int *b=(int*)malloc(n*sizeof(int));		// ��������������� ������������� ������
book *inf;
for (int i=0; i<n; i++)
{
	b[i]=i;
}
inf = new book[n];
for (int i=0; i<n; i++)
{
		printf("����� �=%d:\n", i+1);
		printf("\n��� ������: ");
		fflush(stdin); 
		gets(a[i].author);
		
		printf("�������� �����: ");
		fflush(stdin);
		gets(a[i].title);
		
		printf("������������: ");
		fflush(stdin);
		gets(a[i].publ);
		
		printf("��� �������: ");
	
		while(!(scanf("%d", &a[i].year)))
		{
			printf_s("������! ������� ��� ���:\n");
			flushall();
		}
		fflush(stdin);
		printf("����� �������: ");
		
		while(!(scanf("%d", &a[i].str)))
		{
			printf_s("������! ������� ��� ���:\n");
			flushall();
		}
		fflush(stdin);
}
// ���������� 
int i, j;
for (i = 0; i<(n - 1); i++)
	{

		for (j = i + 1; j<n; j++)
		{
			if (strcmp(a[j].title, a[i].title)<0)
			{
				swap(a[j], a[i]);
			}
		}

	}
printf("\n����� ����������:\n"); // ����� ����������
for (i = 0; i<n; i++)
{
	j=b[i];
	printf("\n��� ������: %s", a[i].author);
	printf("\n�������� �����: %s", a[i].title);
	printf("\n������������: %s", a[i].publ);
	printf("\n��� �������: %d", a[i].year);
	printf("\n����� �������: %d", a[i].str);
	printf("\n");
}
_getch();
return 0;
}
}
/*
*/