#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

class vchislo
{
	double chis;
	
public:
	vchislo()				// Конструктор без параметров создает "пустой" объект
	{
		chis=0;
	}
	
	vchislo(double ch)		// Конструктор для инициализации полей
	{
		chis=ch;
	}	

	int method()			// Функция вычисления
	{
		int a=0, b=chis/10;
		while (1)
		{
			if (b!=0) 
		    {
		        a++;
		        b/=10;
		    }
			else 
			{
				a++;
				break;
			}
		}
        return a;
		}
		
	void print()			// Функция для печати полей объекта
	{
	    cout<<"Количество цифр в целой части числа = ";
	    cout<<method();
	}
};
 
void main()
{
    setlocale (LC_ALL, "Russian");
    double c;
    cout << "Введите вещественное число:\n";
    cin>>c;
	vchislo p(c);
    p.print();
    getch();
}