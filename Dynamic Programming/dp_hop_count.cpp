#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int minJumps(vector<int> Array)
{
	vector<int> jumpArray(Array.size());

	jumpArray[0] = 0;

	for(int i = 1; i <n ; i++ ) {
		jumpArray[i] = INT_MAX;
		for(int j = 0 ; j < i; j++) {
			if(i <= j + Array[j] && jumpArray[j] != INT_MAX) {
				jumpArray[i] = min(jumpArray[i], jumpArray[i] + 1);
				break;
			}
		}
	
	}

	return jumpArray[n-1];

}


int main()
{

	int n;
	cin >> n;
	
	vector<int> jArray(n);

	cout << minJumps(jArray) << endl;

 	return 0;
}
