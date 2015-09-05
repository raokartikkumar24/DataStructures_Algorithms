/*
*
* Binomial Co-efficient
* Choosing k different things from n things
* Mathematical formula : n!/((n-k)!k!)
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <ostream>

typedef long long int LL;
using namespace std;

LL DP[1024][1024];

void binomial_coeff()
{
	LL i, j;

	for(i = 0 ; i < 1024 ; ++i)
	  DP[i][0] = 1; //chosing empty thing from n things is 1, the empty set itself

	for( i = 0 ; i < 1024; ++i)
		DP[i][i] = 1; //choosing k things from k things (k k) ==  1

	// otherwise (n,k) == n!/(n-k)!k!
	//this corresponds to the summation of the top 2 cells above the current cell
	for(i = 1; i < 1024 ; ++i)
		for(j = 1; j < i; ++j)
			DP[i][j] = DP[i-1][j] + DP[i-1][j-1];

}

LL bincoff(LL n, LL k)
{
	return DP[n][k];
}

void displayMatrix()
{
	for(LL i = 0 ; i < 1024; ++i)
	{
		for(LL j = 0; j < 1024; ++j)
		{
			cout << DP[i][j] << " ";
		}
		cout << "\n";
	}
}

void displayMatrixInFile()
{
	ofstream outputfile("C:\\temp\\bincoeff.txt");

	for(LL i = 0 ; i < 1024; ++i)
	{
		for(LL j = 0; j < 1024; ++j)
		{
			outputfile << DP[i][j] << " ";
		}
		outputfile << "\n";
	}

}

int main()
{
		
	LL n,k;
	cin >> n >> k;

	binomial_coeff();

//	displayMatrix();

	displayMatrixInFile();

	cout << bincoff(n,k) << endl;

	return 0;
}