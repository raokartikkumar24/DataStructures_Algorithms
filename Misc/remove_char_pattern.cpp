#include<iostream>
using namespace std;

void strRemove(char *source1, char *pat1)
{
	int sl = 0, pl =0;
	for(; source1[sl]!='\0';sl++);
	for(;pat1[pl] != '\0' ;pl++);
	char source[sl], pat[pl];
	
	for(int i = 0 ; i < sl ;i++)
		source[i] = source1[i];
		
	for(int i = 0 ; i < pl; i++)
		pat[i] = pat1[i];
		
		
	int alpha[26] = {0};
	
	for(int i = 0 ; i < pl ; i++)
		alpha[pat[i]-'a']++;
		
		
		cout<<endl;
		int c = 0; 
	for(int i = 0 ; i < sl ; i++)
	{
		
		if( source[i] != ' ')
		{
			if( alpha[source[i]-'a'] > 0 )
			{
				c++;
				source[i] = '.';
			}
				
		}	
		
		
	}
	char *newstr = new char[sl-c];
	int c1=0;
	int p = 0;
	for(int i = 0 ; i < sl ;i++)
	{
		if( source[i] != '.' )
			newstr[c1++] = source[i];
	}
		
	
	for(int i = 0 ; i< sl-c ; i++)
		cout<<newstr[i];

	/*int  x = 0;
	for(int i = 0 ; i < sl; i++)
	{
		x = i+1;
		if( source[i] == '.' )
		{
			while( source[x++] != '.')
				source[i] = source[x];
		}
	}	

	cout<<endl;
	for(int i = 0 ; i< sl ; i++)
		cout<<source[i];*/
	
	cout<<endl;
}

int main()
{
	strRemove("oracle development center","elt");
	return 0;
}
