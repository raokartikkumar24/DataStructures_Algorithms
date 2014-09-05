#include<iostream>
#include<string>
#include<map>
#include<conio.h>
using namespace std;

void intersection(string str1, string str2)
{
	map<int,string> mapIntersection;
	int str1len = 0, str2len = 0;
	for(;str1[str1len] != '\0' ;str1len++);
	for(;str2[str2len] != '\0' ;str2len++);
	
	int len = str1len > str2len ? str1len : str2len;
	
	for(int i = 0 ; i < len ; )
	{
		int l = 0 ;
		int j = 0;
		string inter;
		while( str1.at(i) == str2.at(i) )
		{
			l++;
			inter[j++] = str1.at(i);
			i++;
			mapIntersection[l] = inter;

		}
		i++;
	}
	
	map<int, string>::iterator it = mapIntersection.begin();
	
	for(; it != mapIntersection.end(); it++)
	 cout<<it->second;
	 
	 cout<<endl;
	
	
}

int main()
{
	string str1, str2;
	getline(cin,str1);
	getline(cin,str2);
	_getch();
	intersection(str1,str2);
	
	return 0;

}
