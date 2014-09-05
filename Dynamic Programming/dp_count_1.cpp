//Basic DP program : Top down approach
//1. subtract number by 1
//2. if the number is divisible by 2 then half it.
//3. if the number is divisible by 3 then divide by 3

#include<iostream>
using namespace std;

int *memo = NULL;
int getmin(int n)
{
	if ( n == 1 )  return 0;  // base case
	if( memo[n] != -1 ) return memo[n];  // we have solved it already :)
	int r = 1 + getmin( n - 1 );  // '-1' step .  'r' will contain the optimal answer finally
	if( n%2 == 0 )   r  =  min( r , 1 + getmin( n / 2 ) ) ;  //  '/2' step
	if( n%3 == 0 )   r  =  min( r , 1 + getmin( n / 3 ) ) ;  //  '/3' step
	memo[n] = r ;  // save the result. If you forget this step, then its same as plain recursion.

	return r;

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