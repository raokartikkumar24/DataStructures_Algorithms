#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string>
using namespace std;

char* dectobinary(char *a)
{
	int dotc=0;
	for(int i=0 ; a[i] != '\0' ;i++)
	{
		if( a[i] == '.')
			 dotc++;

		if( a[i] == ',' )
			return "ERROR";
	}

	if( dotc > 1) return "ERROR";
	
	double s = atof(a);
	int intpart = (int)s;
	double remain = s - (double)intpart;

	int c = 0;
	int intpart2 = intpart;
	int stemp;
	while(intpart > 0 )
	 {
		stemp =intpart%2;
		intpart/=2;
		c++;
	}	
	int *temp = new int[c];
	c = 0;
	while( intpart2 > 0 )
	 {
		temp[c++] =intpart2%2;
		intpart2/=2;
	 }	

	char *p =new char[c+5];
	int j = c;
	int ii = 0;
	for( ; ii < c ; ii++ )
	{
		p[ii] = '0' + temp[--j];
	}

	p[ii] = '.';
	ii++;
	cout<<endl;
	int cc = 0 ;
	
	while( cc++ != 4 )
	{
		 	remain*=2;	
			int t = (int)remain;
			p[ii++] = '0' +(char) t;
			remain = remain - (int)remain;
	}
	return p;
	
}

int main()
{
 	char *in = new char;
	gets(in);
	char *ans = dectobinary(in);

	puts(ans );

}
