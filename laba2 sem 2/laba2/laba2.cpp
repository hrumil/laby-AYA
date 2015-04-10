/*	Класс - книга. Параметры (поля): автор, название, количество экземпляров и количество 
	желающих ее прочитать читателей. 
	Класс включает: конструктор и функцию определения средней длины очереди на чтение 
	каждого экземпляра, при необходимости функции доступа к полям, функцию печати параметров. 
	Напечатать параметры книг и наиболее читаемую книгу в библиотеке. */

#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

	class book
	{
		char author[64];	// автор
		char name[64];		// название
		int ekz;			// количество экземпляров
		int chit;			// количество желающих прочитать книгу 
	
	public:

		book()				// Конструктор без параметров создает "пустой" объект
		{
			author[0]=name[0]=ekz=chit=0;
		}

		void set(char a[], char n[], int e, int ch)	// Функция для инициализации полей для  созданного "пустого" объекта
		{							
			strcpy(author, a);						// Копируем строку, содержащую автора
			strcpy(name, n);						// Копируем строку, содержащую название
			ekz=e;									// Задаем значение количества экземпляров
			chit=ch;								// Задаем значение количества читателей
		}

		book(char *a, char *n, int e, int ch)		// Конструктор для инициализации полей
		{
			strcpy(author, a);						// Копируем строку, содержащую автора
			strcpy(name, n);						// Копируем строку, содержащую название
			ekz=e;									// Задаем значение количества экземпляров
			chit=ch;								// Задаем значение количества читателей
		}
		
		double och(int e, int ch)					// Функция возвращает среднюю длину очереди
		{
			return(double(ch)/double(e));
		}

		void print()								// Функция для печати полей объекта
		{
			cout<<"\n\nauthor: "<<author<<", name: "<<name<<", ekz="<<ekz<<" chit="<<chit;
		}
	};
	
	void main()
	{
		int n;										// Неизвестное число объектов
		cout<<"n="; 
		cin>>n;
		
		if(n>=1)
		{
			char a1[64], n1[64];		
			int e, ch;
			book *pb=new book[n];
			double *och=new double[n];
			for (int i=0; i<n; i++)
			{
				cout<<"\n\nObject N="<<(i+1)<<"\nauthor: ";
				cin>>a1;
				cout<<"name: ";
				cin>>n1;
				cout<<"ekz=";
				cin>>e;
				cout<<"chit=";
				cin>>ch;
				pb[i].set(a1, n1, e, ch);			// Вызываем функцию set для инициализации полей объекта
				och[i]=pb[i].och(e,ch);	
			}
// Нахождение максимального элемента		
			double max=0; 
			int k=0;
 			for(int i=0; i<n; i++)	
			{
				if(och[i] > max) 
				{ 
					max = och[i]; 
					k=i;
				}
			}
			for(int i=0; i<n; i++)					
			{
				pb[i].print();
				cout<<" ochered="<<och[i];
			}
			cout<<"\n\nmax ochered="<<max<<" from next object:";
			pb[k].print();							// Печать полей наиболее читаемой книги
		}

		else cout<<"Error!";
		_getch();
	}