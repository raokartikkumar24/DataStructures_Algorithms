#include<iostream>
using namespace std;

int fact(int n)
{
	if( n == 0 ) return 0;
	if( n == 1 ) return 1;
	else
	 return (n * fact(n-1));
}


void fact2(int num)
{
	int f = 1;
	for(int i = num ; i > 0 ; i--)
		 f *=i;
		 
cout<<f<<endl;
}

int main()
{
	cout<<endl<<fact(0)<<endl;
	fact2(5);
	return 0;
}