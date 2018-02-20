#include <iostream>

using namespace std;

int getMaxCost(int array[], int n) {

	int values[n+1];
	values[0] = 0;
	int i,j;

	for(i = 1; i <= n ; i++) {
		int maximum_value = -1;
		for(j = 0 ; j < i; j++ ){
			maximum_value = max(maximum_value,array[j] + values[i-j-1]);
		}
		values[i] = maximum_value;
	}

	return values[n];

}


int main() {

	int N;
	cin >> N;

	int prices[N];
	for(int i = 0 ; i < N ; i++)
		cin >> prices[i];

	cout << getMaxCost(prices,N) << "\n";

	return 0;
}
