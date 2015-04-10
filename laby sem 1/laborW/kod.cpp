/*
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include <math.h>
#include <ctime>
#include <iostream>
#include <memory.h>

struct book // Создание структуры
	{
		char author[64];	// ФИО автора
		char title[64];	// название книги
		char publ[64];		// издательство
		int year;		// год издания
		int str;		// число страниц
	};
struct List // Создание списка
{
	book book; // Инф. поле
	List *pNext, *pPred; // Указатель на следующий и предыдущий элементы
};

// Функция добавить элемент в двухсвязный кольцевой список (в начало или в конец)
void add(List *&pF, List *p, bool first)
{ // Если first равен true, то элемент будет первым
	if (pF==0) // Список пуст
	{
		pF=p->pNext=p->pPred=p;
		return;
	}
	p->pNext=pF;
	p->pPred=pF->pPred;
	pF->pPred->pNext=p;
	pF->pPred=p;
	if (first) pF=p; // Элемент будет первым
}

// Функция добавления элемента в начало списка
void addFirst(List *& pF,List* p) // Указатель на начало списка и на добавляемый элемент
{
	p->pNext = pF;
	pF = p;
}

// Удаление элемента из начала списка
List *delFirst(List *&pF) // Функция возвращает указатель на удаляемый элемент
{
	if (pF == 0) return 0;
	List *p = pF;
	pF = pF->pNext;
	return p;

};

// Добавление элемента перед заданным
bool add(List *&pF, List * pZad, List *p)
{
	// Функция возвращает true при нормальном завершении и false в случае ошибки
	if (pZad == pF) // Элемент будет первым
	{
		p->pNext = pF;
		pF = p;
		return true;
	}

	List *pPred = pF; // Указатель на предыдущий элемент перед pZad
	while (pPred->pNext != pZad && pPred->pNext)
		pPred = pPred->pNext;
	if (pPred->pNext == 0) return false; // Элемента pZad нет в списке
	p->pNext = pZad;
	pPred->pNext = p;
	return true;
};

// Удаление любого элемента p из списка
List * del(List*& pF, List *p) // Функция возвращает указатель на удаленный элемент
{
	if (pF == 0) return 0;
	if (pF == p) // Удаляем первый элемент
	{
		pF = pF->pNext;
		return p;
	}
	else
	{
		List *pPred = pF; // Указатель на предыдущий элемент перед p
		while (pPred->pNext != p && pPred->pNext)
			pPred = pPred->pNext;
		if (pPred->pNext == 0) return 0; // Элемента p нет в списке
		pPred->pNext = p->pNext;
		return p;
	}
	while (delFirst(pF)); // Очистка списка
};

	// Функция вставляет элемент в двухсвязный кольцевой список после заданного
void addInList(List *pZad, List *p)
{
	p->pPred=pZad;
	p->pNext=pZad->pNext;
	pZad->pNext->pPred=p;
	pZad->pNext=p;
}

// Функция извлекает элемент p из списка
List * remove(List *&pF, List *p)
{
	if (pF==0) return 0;
	if (pF->pNext==pF) // Список состоит из 1 элемента
	{
		if (p==pF) 
		{
			pF=0;
			return p;
		}
		else return 0; // Ошибка
	}
	if (p==pF) // Извлекаемый элемент первый
		pF=pF->pNext; // Второй будет первым
	p->pPred->pNext=p->pNext;
	p->pNext->pPred=p->pPred;
	return p;
}

using namespace std;
void main()
{
	setlocale(LC_ALL, "Russian");
	List *pF = 0; // Список пуст
	List *p;

	// Ввод списка
	char Ch; // Переменная для ввода условия продолжения ввода
	do
	{
		p = (List*)malloc(sizeof(List)); // Выделяем память под элемент
		printf("\nФИО автора: ");
		fflush(stdin); 
		//gets(p->book.author);
		cin >> p->book.author;
	
		printf("Название книги: ");
		fflush(stdin);
		//gets(p->book.title);
		cin >> p->book.title;

		printf("Издательство: ");
		fflush(stdin);
		//gets(p->book.publ);
		cin >> p->book.publ;

		printf("Год издания: ");
		fflush(stdin); 
		//scanf_s("%lf", &p->book.publ);
		cin >> p->book.publ;

		printf("Число страниц: ");
		fflush(stdin);
		//scanf_s("%lf", &p->book.str);
		cin >> p->book.str;

		add(pF, p, false); // Добавляем элемент в начало списка
		printf("For continue press j else any key! ");
		Ch = getche();
	}
	while (Ch=='j');

	// Сортировка списка методом пузырька
	while(1)
	{
		bool zamena=false;
		List *p1=pF, *p2=pF->pNext;
		do
		{
			if (strcmp(p1->book.title,p2->book.title)>0) // Элементы надо поменять (сортировка по названию)
			{
				p1=remove(pF, p1); // Извлекаем p1
				if (p1==0)
				{
					printf("List Error!!!!");
					getch();
				}
				addInList(p2, p1); // Добавляем после второго
				p2=p1->pNext;
				zamena=true; // Замена произошла
			}
			else // Элементы не поменяли
			{
				p1=p2;
				p2=p2->pNext;
			}
		}
		while(p2!=pF);
		if (!zamena) // Если замены не было список отсортирован
			break;
	}
	
	// Вывод спиcка
	for (List *pi = pF; pi; pi = pi->pNext)
		printf("\n%s %s %s %d %d", pi->book.author, pi->book.title,
		pi->book.publ, pi->book.year, pi->book.str);
	
	getch();
}

*/

/*
// Сортировка списка методом пузырька
	while(Ch == 'j');
	
	int k=0;
	if (pF==pF->pNext)
	{
		printf("список отсортирован");
	}

	while(k==0)
	{
		bool zamena=false;
		List *p1=pF, *p2=pF->pNext;
		do
		{
			if (strcmp(p1->book.title,p2->book.title)>0) // Элементы надо поменять (сортировка по фамилии)
			{

				p1=remove(pF, p1); // Извлекаем p1
				addInList(p2, p1); // Добавляем после второго
				p2=p1->pNext;
				zamena=true; // Замена произошла
			}
			else // Элементы не поменяли
			{
				p1=p2;
				p2=p2->pNext;
			}
		}
		while(p2!=pF);
		if (!zamena) // Если замены не было список отсортирован
			k=1;
	}
	*/