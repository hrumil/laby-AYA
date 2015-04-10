// Объект - книга (поля: ФИО автора, название, издательство, год издания, число страниц) 
// Сортировка по названию методом обмена («пузырька») по названию книги


/*
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <locale>

using namespace std;

struct book 				// Создание структуры
	{
		char author[64];	// ФИО автора
		char title[64];		// название книги
		char publ[64];		// издательство
		int year;			// год издания
		int str;			// число страниц
	};

int main(int argc, char* argv[])
{
setlocale(LC_ALL, "Russian");
int n;
printf("Введите число книг: ");
scanf("%d", &n);
if(n>0)
{
book *a= (book*)malloc(n*sizeof(book));
int *b=(int*)malloc(n*sizeof(int));		// Вспомогательный сортировочный массив
book *inf;
for (int i=0; i<n; i++)
{
	b[i]=i;
}
inf = new book[n];
for (int i=0; i<n; i++)
{
		printf("Книга №=%d:\n", i+1);
		printf("\nФИО автора: ");
		fflush(stdin); 
		gets(a[i].author);
		
		printf("Название книги: ");
		fflush(stdin);
		gets(a[i].title);
		
		printf("Издательство: ");
		fflush(stdin);
		gets(a[i].publ);
		
		printf("Год издания: ");
	
		while(!(scanf("%d", &a[i].year)))
		{
			printf_s("Ошибка! Введите еще раз:\n");
			flushall();
		}
		fflush(stdin);
		printf("Число страниц: ");
		
		while(!(scanf("%d", &a[i].str)))
		{
			printf_s("Ошибка! Введите еще раз:\n");
			flushall();
		}
		fflush(stdin);
}
// Сортировка 
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
printf("\nПосле сортировки:\n"); // Вывод сортировки
for (i = 0; i<n; i++)
{
	j=b[i];
	printf("\nФИО автора: %s", a[i].author);
	printf("\nНазвание книги: %s", a[i].title);
	printf("\nИздательство: %s", a[i].publ);
	printf("\nГод издания: %d", a[i].year);
	printf("\nЧисло страниц: %d", a[i].str);
	printf("\n");
}
_getch();
return 0;
}
}
/*
*/