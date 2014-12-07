#include<iostream>
#include<vector>
#include<ctime>
typedef long long LL;
using namespace std;

void PrintPrimeFactors(LL N)
{

	vector<LL> primefactors;

	vector<bool> sieve(N+1);

	sieve[0] = sieve[1] = false;

	for(LL j = 0 ; j < N+1 ; j++)
		sieve[j] = true;

	LL i = 2;


	clock_t begin = clock();
	while(i*i <= N)
	{
			if(sieve[i] == true)
			{
				LL k = i*i;
				while( k <= N)
				{
					sieve[k] = false;
					k += i;
				}

							
			}

		i += 1;
	}

	clock_t end = clock();

	cout<<"Time taken to create the prime numbers : "<<(end-begin)<<" "<<(end-begin)/CLOCKS_PER_SEC;


	for(LL j = 2; j <= N ; j++)
	{

		if(sieve[j]) {
			//cout<<j<<endl;
			primefactors.push_back(j);
		}
	}

}

int main()
{

	LL number;
	cin>>number;
	PrintPrimeFactors(number);
	return 0;

}
