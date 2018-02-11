#include <iostream>
#include <algorithm>

using namespace std;

//recursive solution
int eggDrops(int n , int k) {

	if(k == 0 || k == 1 ) return 1;
	if(n == 1) return k;

	int x, res = INT_MAX;

	for(x = 1 ; x <= k; x++) {
		int val = max(eggDrops(n-1,k-1), eggDrops(n,k-x));
		if(val < res) {
			res = val;
		}
		
	}
	return res+1;

}



//Dp solution
int getNumberOfTrials(int eggs, int floors) {
    
    int eggFloor[eggs+1][floors+1];
    
    //1 egg and 0 or 1 floor
    for(int i = 1 ; i <=eggs ; i++) {
        eggFloor[i][1] = 1;
        eggFloor[i][0] = 0;
    }
    
    //1 egg and k floors --> k
    for(int i = 1 ; i <=floors; i++) {
        eggFloor[1][i] = i;
    }
    
    
    //Main part
    int i, j, x;
    int res;
    for(i = 2 ; i <= eggs ; i++) {
        for(j=2; j <= floors; j++) {
            eggFloor[i][j] = INT_MAX;
            for(x = 1; x < j; x++) {
                res  = 1 + max(eggFloor[i-1][x-1], eggFloor[i][j-x]);
                if(res < eggFloor[i][j]) {
                    eggFloor[i][j] = res;
                }
            }
        }
        
    }
    
    return eggFloor[eggs][floors];
    
}

int main()
{
    
    int eggs, floors;
    cin >> eggs >> floors;
    
    cout << getNumberOfTrials(eggs,floors) << endl;
    
    return 0;
}

