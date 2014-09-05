#include<iostream>
#include<stdlib.h>
using namespace std;

void strRemove(char *source, char *pattern)
{
	int sourceLength = 0;
	int patlength = 0;
	for(; source[sourceLength] != '\0' ;sourceLength++);
	for(; pattern[patlength] != '\0' ;patlength++);
	int j = 0;
	for(int i = 0 ; i < sourceLength ; i++)
	{
		if( source[i] == pattern[j] )
		{
			source[i] = source[i+1];
			i++;j++;
		}
		
		else if( j == patlength ) j =0;
		
		else j++;
	}
	
	for(int i = 0; i < sourceLength ;i++)
		cout<<source[i];
	cout<<endl;
}

int main()
{
	char *sr = new char[27];
	char *pat = new char[4];
	
	cout<<"enter source";
	gets(sr);
	cout<<"enter pattern";
	gets(pat);
	
	strRemove(sr,pat);
	
	return 0;
}
