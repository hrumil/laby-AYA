#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <conio.h>
using namespace std;
/**Direct order: */
void Direct(int *parents, int n, int p)
{
	cout<<p;
	for (int i=0; i<n; i++)
		if(parents[i]==p)
			Direct(parents, n, i+1);
}
/**Reverse order: */
void Reverse(int *parents, int n, int p)
{
	for(int i=0; i<n; i++)
		if(parents[i]==p)
			Reverse(parents, n, i+1);
	cout<<p;
}
/**Symmetrical order:*/
void Symmetrical(int *parents, int n, int p)
{
	int x=1;
	for(int i=0; i<n; i++)
	{
		if(parents[i]==p)
		{
			Symmetrical(parents, n, i+1);
			if(x) 
			{
				cout<<p;
				x=0;
			}
		}
	}
	if(x)
		cout<<p;
}
/**void main() */
void main()
{
	int n, *parents;
	cout<<"Enter number of elements: ";
	cin>>n;
	parents=new int[n];
	cout<<"Enter parents:\n";
	for (int i=0; i<n; i++)
		{
			cin>>parents[i];
		}

	cout<<"\nDirect order: ";
	Direct(parents, n, 1);

	cout<<"\nReverse order: ";
	Reverse(parents, n, 1);

	cout<<"\nSymmetrical order: ";
	Symmetrical(parents, n, 1);

	_getch();
}
