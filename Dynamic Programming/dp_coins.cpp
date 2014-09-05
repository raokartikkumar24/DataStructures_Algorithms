#include<iostream>
using namespace std;

void getDenominations(int n)
{
	int *min = new int[n+1];
	for(int k = 0 ; k <= n ; k++)
		min[k] = 9999 ;
		
	// int min[n] = { -1 };	
	min[0] = 0;
	int i = 1;
	int v =0;
	for(; i <= n ; i++)
	 {
		for(v=0; v < 4 ; v++)
		{
			if( ( a[v] <= i ) && ( (min[i - a[v]] + 1) < min[i] ))
			{
				min[i] = min[i-a[v]] + 1;
			}
		}
	 }
	 
	for( int j  = 0 ; j <= n ; j++)
		cout<<min[j]<<endl;
	
	cout<<endl;
	
}

int main()
{
	getDenominations(10);
	return 0;
}