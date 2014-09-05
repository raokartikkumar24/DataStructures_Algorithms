#include<iostream>
using namespace std;

int main()
{

	int number;
	cin>>number;
	int arr[10] = {0};
	int rem;

	if( number > 10 )
	{
		while( number / 10 != 0 )
		{
			rem = number % 10;
			if( rem == 0 ) arr[rem]++;
			else arr[rem-1]++;
		
			number = number /10;
		
			if( number < 10 ) 
			{
				if( rem == 0 )
					arr[number]++;
				else
					arr[number-1]++;
			}
			cout<<"Number : "<<number<<" rem : "<<rem<<endl;

		}

	}

	else
	{
		arr[number]++;
	}

	for(int i = 0 ; i < 10; i++)cout<<arr[i]<<" ";

	cout<<endl;
	
	return 0;
}
