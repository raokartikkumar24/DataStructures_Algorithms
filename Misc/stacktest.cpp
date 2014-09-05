#include<iostream>

using namespace std;

int printall(int number);

int main()
{

	printall(5);
	return 0;	
}

int printall(int number)
{
	if( number > 0 )
	{
	 printall(number-1);
	cout<<number<<endl;
	}
}
