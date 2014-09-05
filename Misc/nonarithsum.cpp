#include<iostream>
using namespace std;

int nonarithSum(int a, int b )
{
	if( b == 0 ) return a;
	int sum = a ^ b;
	int carry = ( a & b ) << 1;
	cout<<"carry is : "<<carry<<" for a : "<<a<<" and b : "<<b<<endl;
	return nonarithSum( sum, carry );

}

int main()
{
cout<<nonarithSum( 5, 5 )<<endl;

return 0;
}