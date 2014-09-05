#include<iostream>
using namespace std;

int main()
{

	char a[] = "my name";
	int len = 0; int sp = 0;
	for( ; a[len] != '\0' ;len++)
	{

		if( a[len] == ' ')
			sp++;

	}

	for(int p = 0 ; p < len ; p++ ) cout<<a[p];

	cout<<endl;

	char *rev = new char[len];
	int c = 0;
	for(int i = len; i >= 0 ; i-- )
		rev[c++] =  a[i];
	rev[c] = '\0';

	for(int i = 0 ; i <= len ; i++ )
		cout<<rev[i];

	cout<<endl;

	c=0;
	int x = 0;
	sp +=1;
	while( sp-- )
	{

		c =x;
		while( rev[c++] != ' ' ) //get the length
		{	
			if( rev[c] == '\0' ){ c = c+1; break;}

		}


		for(int i = c-2 ; i >= x ;i--)
			cout<<rev[i];

		cout<<" ";
		x = c;
	}
	cout<<endl;

		

}
