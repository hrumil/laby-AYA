
#include <iostream>
#include <conio.h>

using namespace std;

class avto					// ������� �����
{
protected:
	char *name;				// �����
	double vmax;			// ������������ ��������
public:
	avto(char *pn, double vmax1)
	{
		name = pn;
		vmax=vmax1;
	}
	virtual void print()	// ����������� ��� ������������� �����
	{
		cout<<"\nName: "<<name<<", Max speed="<<vmax;
	}
};

class bus: public avto	// ����������� �����
{
	int psg;
public:
	bus(char *name, double vmax, int psg1):	// ����������� ��� ������������� �����
	avto(name, vmax)						// ����� ����� ������������ �������� ������
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
	avto a1("Nissan", 200);			// ��������� ������ � ������� ������������
	bus b1("Volkswagen", 120, 13);	// ��������� ������ � ������� ������������
	avto *c;						// ��������� ���� �������� ������
	c=&a1;							// ����������� �� ������ �������� ������
	c->print();					// ����� ������ ����� ���������
	c=&b1;						// ���������� ��������� �� ������ ������������ ������ 
	c->print();					// ����� ������ ����� ���������, ���������� ����� ������ bus
	_getch();
}

