
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

using namespace std;

#define MAX 100

char *p[MAX], *pull(void);
int spos = 0;				// индекс следующего свободного места
int rpos = 0;				// индекс следующего элемента, подлежащего выборке(удаление)
void enter(void), store(char *q), review(void), delete_ap(void), pop(void);

/**int main(void) */
int main(void)
{
	setlocale(LC_ALL, "Russian");
	char s[80];
	
	for(;;) 
	{
		cout<<"\nEnter element (Q), Review spisok (W), Delete element (E),\n\
Pokazat soderjimoe vershiny steka (R), Exit (T): ";
		
		gets(s);
		*s = toupper(*s);

		switch(*s) 
		{
			case 'Q':
				enter();
				break;
			case 'W':
				review();
				break;
			case 'E':
				delete_ap();
				break;
			case 'T':
				exit(0);
			case 'R':
				pop();
				break;
		}
	}
	return 0;
}

/** vstavka v stek new element*/
void enter()
{
  char s[256], *p;

	do
	{
		cout<<"Enter element"<<spos+1<<":";
		gets(s);
		if(*s==0)
			break; // запись не была произведена 
		p=(char*)malloc(strlen(s)+1);
		if(!p) 
		{
			cout<<"Ne hvataet pamyati.\n";
			return;
		}
		strcpy(p,s);
		if(*s)
			store(p);
	} 
	while(*s);
}
/** Prosmotr soderjimogo steka*/
void review(void)
{
	int t;
	if(rpos==spos) 
	{
		cout<<"Elementov bolshe net\n";
		return;
	}
  	for(t=rpos; t < spos; ++t)
		cout<<t+1<<". "<<p[t]<<endl;
}
/** delete element iz steka*/
void delete_ap(void)
{
	char *p;
	if((p=pull())==NULL) 
		return;
	cout<<p<<endl;
}
/** vstavka elementa*/
void store(char *q)
{
	if(spos==MAX) 
	{
		cout<<"Mest bolshe net\n";
		return;
	}
	p[spos] = q;
	spos++;
}

/** izvlechenie elementa */
char *pull(void)
{
	spos--;
	return p[spos];
}
/** poluchenie verhnego elementa iz steka*/
void pop(void)
{
	cout<<1<<". "<<p[0]<<endl;
}
