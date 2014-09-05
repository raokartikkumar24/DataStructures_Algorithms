#include<stdio.h>
#include<iostream>



long long fact(long long n );

int main()
{
 	int num;
	scanf("%d",&num);
	
	long long res = fact(num);
	printf("%lld",res);
	

	return 0;
}

long long fact(long long n )
{
	if( n == 0 ) return 1;
	else
	{
		for(long long i = n-1 ; i >=1 ; i--)
			n = n*i;
	}
	return n;

	
	  
}
