#include <iostream>
#include <locale>
#include <conio.h>

using namespace std;

void main()
{
	setlocale(LC_ALL,"Russian");
	int n, i, j;
	cout<<"������� ���-�� ����� � �������: ";
	cin>>n;
	unsigned char *a = new unsigned char[n];
	cout<<"������� �������� �������:"<<endl;
	for(i=0; i<n; i++)		cin>>a[i];
	
// ���������� 
	for (i=0; i<n; i++)
		for (j=n-1; j>i; j--)
			if (a[j]<a[j-1])
				swap(a[j], a[j-1]);
	for (i=0; i<n; i++)		cout<<a[i]<<" ";
	_getch();
}