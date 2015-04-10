
#include <iostream>
#include <conio.h>

using namespace std;

class avto					// Базовый класс
{
protected:
	char *name;				// Марка
	double vmax;			// Максимальная скорость
public:
	avto(char *pn, double vmax1)
	{
		name = pn;
		vmax=vmax1;
	}
	virtual void print()	// Конструктор для инициализации полей
	{
		cout<<"\nName: "<<name<<", Max speed="<<vmax;
	}
};

class bus: public avto	// Производный класс
{
	int psg;
public:
	bus(char *name, double vmax, int psg1):	// Конструктор для инициализации полей
	avto(name, vmax)						// Явный вызов конструктора базового класса
	{
		psg=psg1;
	}
	void print()
	{
		avto::print();
		cout<<", Max passengers="<<psg;
	}

};

void main()
{
	avto a1("Nissan", 200);			// Создается объект с вызовом конструктора
	bus b1("Volkswagen", 120, 13);	// Создается объект с вызовом конструктора
	avto *c;						// Указатель типа базового класса
	c=&a1;							// Настраиваем на объект базового класса
	c->print();					// Вызов метода через указатель
	c=&b1;						// Настриваем указатель на объект производного класса 
	c->print();					// Вызов метода через указатель, вызывается метод класса bus
	_getch();
}

