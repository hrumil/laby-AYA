// ���� ����������� � �������� ������
// ��������� ��������� (����: ��� ����������, �������� �������, 
// ����� ����������� ������, ������ �������� �����, ��� ����������)

/*

#include <stdio.h>
#include <stdlib.h>
#include <locale>
#include <iostream>
#include <conio.h>

struct computer
{
	char proc[128];		// ��� ����������
	float tch;			// �������� ������� 
	float ozu;			// ����� ����������� ������
	float hdd;			// ������ �������� �����
	char vkarta[128];	// ��� ����������
};

void main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	int n;												// ����������, �������� ����� ��������� �������
	computer *comp;	
	FILE *pF=fopen("D:\\������\\MyBook.dat", "rb");		// ��������� ���� ��� ������ � �������� ������
	if (pF==0)
	{
		printf("������! ���� �� ������");
	}
	fread(&n, sizeof(int), 1, pF);						// ������ �� ����� ����� ��������� �������
	comp=new computer[n];								// �������� ������ ��� ������ �������� 
	fread(comp, sizeof(computer), n, pF);				// ������ �� ����� ������ 
	fclose(pF);											// ������ �� ����� ������
	for (int i=0; i<n; i++)								// ����� ������ �� �����
	{
		printf("��������� �%d\n", i+1);
		printf("��� ����������: %s\n�������� �������: %.2f\n����� ����������� ������: %.2f\n������ �������� �����: %.2f\n��� ����������: %s\n\n", comp[i].proc, comp[i].tch, comp[i].ozu,
			comp[i].hdd, comp[i].vkarta);
	}
	_getch();
}













/*
fscanf(pF, "%d\n", &n);
comp=new computer[n];	
for (int i=0; i<n; i++)								// ����� ������ �� �����
	{
		fscanf(pF, "��� ����������: %s\n�������� �������: %.2f\n����� ����������� ������: %.2f\n������ �������� �����: %.2f\n��� ����������: %s\n\n", comp[i].proc, comp[i].tch, comp[i].ozu,
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
	std::cout << "��� ������� ������� 1: ";
	std::cin>>k;
	srand(time(NULL));
	int h;
	h=rand()%1000;
	std::cout<<"\n"<<h<<"\n";
	}
	_getch();
}
