
/** \file Исходный код.cpp*/

#include <iostream>
#include <ctime>
using namespace std;

int first, last;
/** прописываем сортировку */
void fastsort(int *mas, int first, int last)
{
	int sr, abc;
	int f=first, l=last;
	sr=mas[(f+l) / 2]; 
	do
	{
		while (mas[f]<sr)
			f++;
		while (mas[l]>sr)
			l--;
		if (f<=l) /**перестановка элементов*/
		{
			abc=mas[f];
			mas[f]=mas[l];
			mas[l]=abc;
			f++;
			l--;
		}
	}
	while (f<l);
	if (first<l) fastsort(mas, first, l);
	if (f<last) fastsort(mas, f, last);
}
/** \void main*/
void main()
{
	int n;
	cout<<"Enter the number of elements:\n";
	cin>>n;
	int *q=new int[n];
	cout<<"Enter the elements:\n";
	for (int i=0; i<n; i++)
		cin>>q[i];
	srand(time(NULL));

	first=0; last=n-1;
	fastsort(q, first, last);	/**Вызов функции*/
	cout<<endl<<"Result fastsort: ";
	for (int i=0; i<n; i++) 
		cout<<q[i]<<" ";
	delete []q;
	system("pause>>void");
}