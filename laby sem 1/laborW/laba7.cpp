// ���� ����������� � �������� ������
// ��������� ��������� (����: ��� ����������, �������� �������, 
// ����� ����������� ������, ������ �������� �����, ��� ����������)

/*

#include <stdio.h>
#include <stdlib.h>
#include <locale>
#include <iostream>

using namespace std;

struct computer
{
	char proc[128];
	float tch;			// �������� �������
	float ozu;			// ����� ����������� ������
	float hdd;			// ������ �������� �����
	char vkarta[128];	// ��� ����������
};

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	int n;
	computer *comp;		
	printf("������� ����� �����������: ");	
	scanf("%d", &n);
	if (n>0)
	{
	comp = new computer [n];	
	for (int i=0; i<n; i++)
	{
		printf("��������� �%d\n", i+1);
		printf("��� ����������: \n");
		fflush(stdin);
		gets(comp[i].proc);

		printf("�������� �������: \n");
		while(!(scanf("%f", &comp[i].tch)))
		{
			flushall();
			printf_s("������! ������� ��� ���: \n");
		}
		fflush(stdin);
				
		printf("����� ����������� ������: \n");
		while(!(scanf("%f", &comp[i].ozu)))
		{
			flushall();
			printf_s("������! ������� ��� ���: \n");
		}
		fflush(stdin);

		printf("������ �������� �����: \n");
		while(!(scanf("%f", &comp[i].hdd)))
		{
			flushall();
			printf_s("������! ������� ��� ���: \n");
		}
		fflush(stdin);

		printf("��� ����������: \n");
		fflush(stdin);
		gets(comp[i].vkarta);
	}
	
	FILE *pF=fopen("D:\\������\\MyBook.dat", "wb");		// ��������� ���� ��� ������ � �������� ������
	fwrite(&n, sizeof(int), 1, pF);						// ���������� � ���� ����� ��������� �������
	fwrite(comp, sizeof(computer), n, pF);				// ���������� � ���� ������
	fclose(pF);											// ��������� ����
	return 0;
	fclose(pF);											// ��������� ����
	return 0;
}
}


















/*
FILE *pF=fopen("D:\\������\\MyBook.dat", "wb");		// ��������� ���� ��� ������ � �������� ������
fprintf(pF, "%d\n", n);
	for(int i=0; i<n; i++)
	{
		printf("��������� �%d\n", i+1);
		printf("��� ����������: %s\n�������� �������: %.2f\n����� ����������� ������: %.2f\n������ �������� �����: %.2f\n��� ����������: %s\n\n", 
			comp[i].proc, comp[i].tch, comp[i].ozu, comp[i].hdd, comp[i].vkarta);// ���������� � ���� ������
	}
*/