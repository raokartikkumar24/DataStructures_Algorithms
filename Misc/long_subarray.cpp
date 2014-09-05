#include<iostream>
using namespace std;

int main()
{

int arr[10] = { -1,-2,5,-2,10,20,-5,6,11,12};

int sum =0;
int st_pos =0, end_pos;
int *subarr;
int i = 0 ;
int l=0;
for(;i<10;i++)
{
	
	sum += arr[i]
	l++;
	if( sum == 0 )
	{
			end_pos = i;
			subarr = new int[end_pos];
			for(int j = 0 ; j <= i ;i++)
				subarr[j] = arr[j];
			
	}
}


return 0;
}