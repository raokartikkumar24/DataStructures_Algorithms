#include<iostream>
using namespace std;

int add(int num, int k)
{
	
	if( k != 0 )
	{
			num += add(num,k-1);
			return num;
	}
	
	return 0;

}

int main()
{

	cout<<add(5,5)<<endl;
	return 0;
}