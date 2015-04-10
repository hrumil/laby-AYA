// Файл открывается в двоичном режиме
// Структура компьютер (поля: тип процессора, тактовая частота, 
// объем оперативной памяти, размер жесткого диска, тип видеокарты)

/*

#include <stdio.h>
#include <stdlib.h>
#include <locale>
#include <iostream>

using namespace std;

struct computer
{
	char proc[128];
	float tch;			// Тактовая частота
	float ozu;			// Объем оперативной памяти
	float hdd;			// Размер жесткого диска
	char vkarta[128];	// Тип видеокарты
};

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	int n;
	computer *comp;		
	printf("Введите число компьютеров: ");	
	scanf("%d", &n);
	if (n>0)
	{
	comp = new computer [n];	
	for (int i=0; i<n; i++)
	{
		printf("Компьютер №%d\n", i+1);
		printf("Тип процессора: \n");
		fflush(stdin);
		gets(comp[i].proc);

		printf("Тактовая частота: \n");
		while(!(scanf("%f", &comp[i].tch)))
		{
			flushall();
			printf_s("Ошибка! Введите еще раз: \n");
		}
		fflush(stdin);
				
		printf("Объем оперативной памяти: \n");
		while(!(scanf("%f", &comp[i].ozu)))
		{
			flushall();
			printf_s("Ошибка! Введите еще раз: \n");
		}
		fflush(stdin);

		printf("Размер жесткого диска: \n");
		while(!(scanf("%f", &comp[i].hdd)))
		{
			flushall();
			printf_s("Ошибка! Введите еще раз: \n");
		}
		fflush(stdin);

		printf("Тип видеокарты: \n");
		fflush(stdin);
		gets(comp[i].vkarta);
	}
	
	FILE *pF=fopen("D:\\Проект\\MyBook.dat", "wb");		// Открываем файл для записи в двоичном режиме
	fwrite(&n, sizeof(int), 1, pF);						// Записываем в файл число элементов массива
	fwrite(comp, sizeof(computer), n, pF);				// Записываем в файл массив
	fclose(pF);											// Закрываем файл
	return 0;
	fclose(pF);											// Закрываем файл
	return 0;
}
}


















/*
FILE *pF=fopen("D:\\Проект\\MyBook.dat", "wb");		// Открываем файл для записи в двоичном режиме
fprintf(pF, "%d\n", n);
	for(int i=0; i<n; i++)
	{
		printf("Компьютер №%d\n", i+1);
		printf("Тип процессора: %s\nТактовая частота: %.2f\nОбъем оперативной памяти: %.2f\nРазмер жесткого диска: %.2f\nТип видеокарты: %s\n\n", 
			comp[i].proc, comp[i].tch, comp[i].ozu, comp[i].hdd, comp[i].vkarta);// Записываем в файл массив
	}
*/