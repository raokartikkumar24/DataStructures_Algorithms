#include<iostream>
using namespace std;

void Ntraverse(int a[])
{
	int count = 0;
	int cache = 0;
	int j;
	int i = 0;
	int element;
	for( ; i < 10 ; )
	{
		j = i;
		while( a[j] == a[i] ) 
		 {
			count++;
			i++;
		 }
		 
		if( count > 1 )
		{
		 	if( count > cache )
			{
				element = a[j];
				cache = count;
				
			}
	    }
		 count = 0;
		 j =i;
		
	}
	if( cache == 0 ) cout<<" all numbers appears once"<<endl;
	else
		cout<<element<<" appears a maximum of "<<cache<<" times "<<endl;
}


int main()
{
	int *arr = new int[10];
	for(int i = 0 ; i < 10;i++)
			cin>>arr[i];
	
	cout<<endl;
	
	Ntraverse( arr );
	cout<<endl;
	
}
