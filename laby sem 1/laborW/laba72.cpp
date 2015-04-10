// Файл открывается в двоичном режиме
// Структура компьютер (поля: тип процессора, тактовая частота, 
// объем оперативной памяти, размер жесткого диска, тип видеокарты)

/*

#include <stdio.h>
#include <stdlib.h>
#include <locale>
#include <iostream>
#include <conio.h>

struct computer
{
	char proc[128];		// Тип процессора
	float tch;			// Тактовая частота 
	float ozu;			// Объем оперативной памяти
	float hdd;			// Размер жесткого диска
	char vkarta[128];	// Тип видеокарты
};

void main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	int n;												// Переменная, задающая число элементов массива
	computer *comp;	
	FILE *pF=fopen("D:\\Проект\\MyBook.dat", "rb");		// Открываем файл для чтения в двоичном режиме
	if (pF==0)
	{
		printf("Ошибка! Файл не найден");
	}
	fread(&n, sizeof(int), 1, pF);						// Читаем из файла число элементов массива
	comp=new computer[n];								// Выделяем память под массив структур 
	fread(comp, sizeof(computer), n, pF);				// Читаем из файла массив 
	fclose(pF);											// Читаем из файла массив
	for (int i=0; i<n; i++)								// Вывод данных на экран
	{
		printf("Компьютер №%d\n", i+1);
		printf("Тип процессора: %s\nТактовая частота: %.2f\nОбъем оперативной памяти: %.2f\nРазмер жесткого диска: %.2f\nТип видеокарты: %s\n\n", comp[i].proc, comp[i].tch, comp[i].ozu,
			comp[i].hdd, comp[i].vkarta);
	}
	_getch();
}













/*
fscanf(pF, "%d\n", &n);
comp=new computer[n];	
for (int i=0; i<n; i++)								// Вывод данных на экран
	{
		fscanf(pF, "Тип процессора: %s\nТактовая частота: %.2f\nОбъем оперативной памяти: %.2f\nРазмер жесткого диска: %.2f\nТип видеокарты: %s\n\n", comp[i].proc, comp[i].tch, comp[i].ozu,
			comp[i].hdd, comp[i].vkarta);
	}
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <conio.h>
#include <locale>

void main()
{
	setlocale(LC_ALL,"Russian");
	int k=1;
	while(k==1)
	{
	std::cout << "Для рандома нажмите 1: ";
	std::cin>>k;
	srand(time(NULL));
	int h;
	h=rand()%1000;
	std::cout<<"\n"<<h<<"\n";
	}
	_getch();
}
