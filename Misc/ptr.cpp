#include<iostream>
using namespace std;

int main()
{
	int a = 5;
	int *p = &a;
	float b = 10.01;
	float *ptr = &b;
	char s = 'a';
	char *str = &s;
	
	cout<<sizeof( p )<<" "<<sizeof( ptr )<<" "<<sizeof( str )<<endl;
	
	return 0;

}