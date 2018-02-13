#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int minJumps(vector<int> Array)
{
	vector<int> jumpArray(Array.size());

	jumpArray[0] = 0;

	for(int i = 1; i < Array.size() ; i++ ) {
		jumpArray[i] = INT_MAX;
		for(int j = 0 ; j < i; j++) {
			if(i <= j + Array[j] && jumpArray[j] != INT_MAX) {
				jumpArray[i] = min(jumpArray[i], jumpArray[i] + 1);
				break;
			}
		}
	
	}

	return jumpArray[Array.size()-1];

}


int main()
{

	int n;
	cin >> n;
	
	vector<int> jArray(n);
    
    for(int i = 0 ; i < n; i++)
        cin >> jArray[i];

	cout << minJumps(jArray) << endl;

 	return 0;
}
