#include<iostream>
using namespace std;

int fun(int v)
{
	if( v==1 || v == 0 ) return 1;
	
	else if ( v%2 == 0 )
		return fun(v/2) + 2;
	else
		return fun(v-1) + 3;
		
}

int main()
{
		cout<<endl<<fun(8)<<endl;
		return 0;
}