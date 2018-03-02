/*
Re arrange the elements in the array such that negative integers are on left and positive integers are on right
No need to maintain the order.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int N;
	cin >> N;
	int pivot = 0;
	vector<int> array(N);

	for(int idx = 0 ; idx < N; idx++)
		cin >> array[idx];

	int i = 0;
	int j = N-1;
	
	while(1) {
	
		while( i < N && (array[i] < pivot)) i++;
		while( j > 0 && (array[j] > pivot)) j--;

		if(i<j) swap(array[i], array[j]);
		else break;
	}

	for(int idx = 0; idx < N; idx++)
		cout << array[idx] << " ";

	return 0;

}
