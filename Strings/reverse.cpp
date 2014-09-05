#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
using namespace std;

int main()
{
	char *str = new char;
	gets( str );
	int len = strlen( str );
	cout<<len<<endl;
	int i = len, j = 0;
	int c = 0;
	char x;
	char cc = 'k', dd = 'a';
	int aa = (int)cc ^(int) dd;
	cout<<aa<<endl;
	for(i = len-1,j=0 ; i >= 0, j < len ; i--,j++)
	{
		x = str[i] ^ str[j];
		cout<<"x : "<<x<<endl;
		str[i] = x ^ str[i];
		str[j] = x ^ str[j];
	}

	for(int i = 0 ; i < len ; i++ )
		cout<<str[i];

	cout<<endl;


	int nn = 5 , nm = 7;
	int temp;
	temp = nn ^ nm;
	nn = temp ^ nn;
	cout<<nn<<endl;
return 0;
	
}

