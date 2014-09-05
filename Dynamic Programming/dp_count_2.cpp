//Basic DP program : bottom up approach
//1. subtract number by 1
//2. if the number is divisible by 2 then half it.
//3. if the number is divisible by 3 then divide by 3

#include<iostream>
using namespace std;

int *memo = NULL;
int getmin(int n)
{
	int i;

	memo[1] = 0;  // trivial case
	
		for( i = 2 ; i <= n ; i++ )
		{
			memo[i] = 1 + memo[i-1];
			if(i%2==0) memo[i] = min( memo[i] , 1+ memo[i/2] );
			if(i%3==0) memo[i] = min( memo[i] , 1+ memo[i/3] );
		}
	return memo[n];
	
}

int main()
{
	int n;
	cin>>n;
	memo = new int[n+1];
	for( int i = 0 ; i < n+1 ; i++)
		memo[i] = -1;
	cout<<getmin(n);
	

}