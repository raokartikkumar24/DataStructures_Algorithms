#include<iostream>
using namespace std;

int main()
{
	int x = 10, y =20;
	int r = x ^ ((x ^ y) & -(x < y));
	cout<<r<<endl;
	
	unsigned int k = 4;
	
	bool x1 = ( k & ( k - 1) ) == 0;
	cout<<x1<<endl;
	
	return 0;
}