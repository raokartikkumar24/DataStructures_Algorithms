#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	char *str = new char;
	gets(str);
	
	int l = 0; 
	for(; str[l] != '\0'; l++);
	int sp = 0;
	for(int i = 0; i < l ; i++)
	{
		if( str[i] == ' ')
			sp++;	
	}

	int newl = l+(sp*2);
	char *newstr = new char[newl-1];
	cout<<"Old length : "<<l<<" "<<"New length :"<<newl<<endl;
	for(int i = 0 ; i < l; i++ )
		{
				newstr[i] = str[i];		

		}

	for(int i = l ; i < newl ; i++)
		newstr[i] = '*';

	
	for(int i = l-1; i >=0 ; i--)
	{
		if( str[i] == ' ')
		{
			str[newl-1] = '0';
			str[newl-2] = '2';
			str[newl-3] = '%';
			newl = newl-3;

		
		}
		else
			{
				str[newl-1]=str[i];
				newl = newl-1;
			}

	}

	return 0;
}
