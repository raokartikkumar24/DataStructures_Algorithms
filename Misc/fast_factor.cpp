#include<iostream>
#include<vector>
typedef long long LL;
using namespace std;

vector<LL> Factors;

void createArray(LL N)
{
	for (LL i = 0; i < N+1; ++i)
		Factors.push_back(0);
	

	LL j = 2;

	while(j*j <= N)
	{
		if(Factors[j] == 0)
		{
			LL k = j * j ;
			while( k <= N )
			{
				if( Factors[k] == 0)
					Factors[k] = j;
				k += j;
			}
		}

		 j += 1;
	}

}

void FastFactorization(LL x)
{
	std::vector<LL> primefactors;

	while(Factors[x] > 0)
	{
		primefactors.push_back(Factors[x]);
		x /= Factors[x];
	}

	primefactors.push_back(x);


	for(int i = 0; i < primefactors.size() ;i++)
		cout<<primefactors[i]<<" ";
	cout<<endl;

}


int main()
{

	LL Number;
	cin>>Number;

	createArray(Number);

	LL factor;
	cin>>factor;

	
	FastFactorization(factor);


	return 0;
}
