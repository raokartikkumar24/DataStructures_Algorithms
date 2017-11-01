#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int N;
		cin >> N;
		vector<int> numbers(N);
		vector<int> dp(N);

		for(int i = 0 ; i < N; i++)
		{
			cin >> numbers[i];
			dp[i] = numbers[i];
		}


		int maxx = numbers[0];

		for(int i = 0 ; i < N; i++)
		{
			for(int j = 0; j < i; j++)
			{
				if(numbers[i] > numbers[j] && dp[i] < dp[j]+numbers[i])
				{	
					dp[i] = dp[j] + numbers[i];
				}

				maxx = max(maxx,dp[i]);
			}
		}

		cout << maxx << "\n";

	}

	return 0;
}
