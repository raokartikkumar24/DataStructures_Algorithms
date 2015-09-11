#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1024
using namespace std;

long len[MAX+1] = {0};

int main()
{
	vector<long> numbers;
	int l;
	cin >> l;
	int i,j;
	for( i = 0 ; i < l; ++i )
	{
		int n;
		cin >> n;
		numbers.push_back(n);
	}

	len[0] = 1;
	for( i=0; i < l ;++i)
	{
		for(j=0 ; j < i ; ++j)
		{
			if(numbers[j] < numbers[i])
				len[i] = len[j] + 1;
		}
	}

	long max_num = len[0];
	for( i = 0 ; i < l ; i++)
		max_num = max(max_num,len[i]);
	cout << max_num << endl;


	return 0;
	

}