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

struct book // �������� ���������
	{
		char author[64];	// ��� ������
		char title[64];	// �������� �����
		char publ[64];		// ������������
		int year;		// ��� �������
		int str;		// ����� �������
	};
struct List // �������� ������
{
	book book; // ���. ����
	List *pNext, *pPred; // ��������� �� ��������� � ���������� ��������
};

// ������� �������� ������� � ����������� ��������� ������ (� ������ ��� � �����)
void add(List *&pF, List *p, bool first)
{ // ���� first ����� true, �� ������� ����� ������
	if (pF==0) // ������ ����
	{
		pF=p->pNext=p->pPred=p;
		return;
	}
	p->pNext=pF;
	p->pPred=pF->pPred;
	pF->pPred->pNext=p;
	pF->pPred=p;
	if (first) pF=p; // ������� ����� ������
}

// ������� ���������� �������� � ������ ������
void addFirst(List *& pF,List* p) // ��������� �� ������ ������ � �� ����������� �������
{
	p->pNext = pF;
	pF = p;
}

// �������� �������� �� ������ ������
List *delFirst(List *&pF) // ������� ���������� ��������� �� ��������� �������
{
	if (pF == 0) return 0;
	List *p = pF;
	pF = pF->pNext;
	return p;

};

// ���������� �������� ����� ��������
bool add(List *&pF, List * pZad, List *p)
{
	// ������� ���������� true ��� ���������� ���������� � false � ������ ������
	if (pZad == pF) // ������� ����� ������
	{
		p->pNext = pF;
		pF = p;
		return true;
	}

	List *pPred = pF; // ��������� �� ���������� ������� ����� pZad
	while (pPred->pNext != pZad && pPred->pNext)
		pPred = pPred->pNext;
	if (pPred->pNext == 0) return false; // �������� pZad ��� � ������
	p->pNext = pZad;
	pPred->pNext = p;
	return true;
};

// �������� ������ �������� p �� ������
List * del(List*& pF, List *p) // ������� ���������� ��������� �� ��������� �������
{
	if (pF == 0) return 0;
	if (pF == p) // ������� ������ �������
	{
		pF = pF->pNext;
		return p;
	}
	else
	{
		List *pPred = pF; // ��������� �� ���������� ������� ����� p
		while (pPred->pNext != p && pPred->pNext)
			pPred = pPred->pNext;
		if (pPred->pNext == 0) return 0; // �������� p ��� � ������
		pPred->pNext = p->pNext;
		return p;
	}
	while (delFirst(pF)); // ������� ������
};

	// ������� ��������� ������� � ����������� ��������� ������ ����� ���������
void addInList(List *pZad, List *p)
{
	p->pPred=pZad;
	p->pNext=pZad->pNext;
	pZad->pNext->pPred=p;
	pZad->pNext=p;
}

// ������� ��������� ������� p �� ������
List * remove(List *&pF, List *p)
{
	if (pF==0) return 0;
	if (pF->pNext==pF) // ������ ������� �� 1 ��������
	{
		if (p==pF) 
		{
			pF=0;
			return p;
		}
		else return 0; // ������
	}
	if (p==pF) // ����������� ������� ������
		pF=pF->pNext; // ������ ����� ������
	p->pPred->pNext=p->pNext;
	p->pNext->pPred=p->pPred;
	return p;
}

using namespace std;
void main()
{
	setlocale(LC_ALL, "Russian");
	List *pF = 0; // ������ ����
	List *p;

	// ���� ������
	char Ch; // ���������� ��� ����� ������� ����������� �����
	do
	{
		p = (List*)malloc(sizeof(List)); // �������� ������ ��� �������
		printf("\n��� ������: ");
		fflush(stdin); 
		//gets(p->book.author);
		cin >> p->book.author;
	
		printf("�������� �����: ");
		fflush(stdin);
		//gets(p->book.title);
		cin >> p->book.title;

		printf("������������: ");
		fflush(stdin);
		//gets(p->book.publ);
		cin >> p->book.publ;

		printf("��� �������: ");
		fflush(stdin); 
		//scanf_s("%lf", &p->book.publ);
		cin >> p->book.publ;

		printf("����� �������: ");
		fflush(stdin);
		//scanf_s("%lf", &p->book.str);
		cin >> p->book.str;

		add(pF, p, false); // ��������� ������� � ������ ������
		printf("For continue press j else any key! ");
		Ch = getche();
	}
	while (Ch=='j');

	// ���������� ������ ������� ��������
	while(1)
	{
		bool zamena=false;
		List *p1=pF, *p2=pF->pNext;
		do
		{
			if (strcmp(p1->book.title,p2->book.title)>0) // �������� ���� �������� (���������� �� ��������)
			{
				p1=remove(pF, p1); // ��������� p1
				if (p1==0)
				{
					printf("List Error!!!!");
					getch();
				}
				addInList(p2, p1); // ��������� ����� �������
				p2=p1->pNext;
				zamena=true; // ������ ���������
			}
			else // �������� �� ��������
			{
				p1=p2;
				p2=p2->pNext;
			}
		}
		while(p2!=pF);
		if (!zamena) // ���� ������ �� ���� ������ ������������
			break;
	}
	
	// ����� ���c��
	for (List *pi = pF; pi; pi = pi->pNext)
		printf("\n%s %s %s %d %d", pi->book.author, pi->book.title,
		pi->book.publ, pi->book.year, pi->book.str);
	
	getch();
}

*/

/*
// ���������� ������ ������� ��������
	while(Ch == 'j');
	
	int k=0;
	if (pF==pF->pNext)
	{
		printf("������ ������������");
	}

	while(k==0)
	{
		bool zamena=false;
		List *p1=pF, *p2=pF->pNext;
		do
		{
			if (strcmp(p1->book.title,p2->book.title)>0) // �������� ���� �������� (���������� �� �������)
			{

				p1=remove(pF, p1); // ��������� p1
				addInList(p2, p1); // ��������� ����� �������
				p2=p1->pNext;
				zamena=true; // ������ ���������
			}
			else // �������� �� ��������
			{
				p1=p2;
				p2=p2->pNext;
			}
		}
		while(p2!=pF);
		if (!zamena) // ���� ������ �� ���� ������ ������������
			k=1;
	}
	*/