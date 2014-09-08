// sub.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include<iostream>
using namespace std;

int main()
{
	int a[] = {1,2,3,4,5,6,1};
	int count = 1;
	int result = 0;
	for(int i = 0 ; i < 7;i++ )
	{
		int j = i + 1;
		int k = i;
		while( a[j] > a[k] )
		{
			//cout<<i<<" "<<j<<endl;
			count++;
			 k =j;
			j++;
		}
		
		if( result < count )
		{
			result = count;
			count = 1;
			
		}
		count = 1;
	
	}
	
	cout<<result<<endl;
	
	return 0;
}
