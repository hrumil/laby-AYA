#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

class vchislo
{
	double chis;
	
public:
	vchislo()				// ����������� ��� ���������� ������� "������" ������
	{
		chis=0;
	}
	
	vchislo(double ch)		// ����������� ��� ������������� �����
	{
		chis=ch;
	}	

	int method()			// ������� ����������
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
		
	void print()			// ������� ��� ������ ����� �������
	{
	    cout<<"���������� ���� � ����� ����� ����� = ";
	    cout<<method();
	}
};
 
void main()
{
    setlocale (LC_ALL, "Russian");
    double c;
    cout << "������� ������������ �����:\n";
    cin>>c;
	vchislo p(c);
    p.print();
    getch();
}