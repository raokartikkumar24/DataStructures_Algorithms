/*
 *  Implementation of range minimum query for getting min values across the range
 *  Segtree size should be
        - if power of 2 -- len * 2 -1
        - else , get the nearest power of 2 and len * 2 -1
    -- so the max size of the auxilary array can be 4*n
 Source - https://www.youtube.com/watch?v=ZBHKZF5w4YU
 */

#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
using namespace std;

void constructSegTree(vector<int> input, vector<int> segTree, int low, int high, int pos) {
    
    if(low == high) {
        segTree[pos] = input[pos];
        return;
    }
    
    int mid = (low+high)/2;
    
    constructSegTree(input, segTree, low, mid, 2*pos + 1);
    constructSegTree(input, segTree, mid+1, high, 2*pos + 2);
    segTree[pos] = min(input[2*pos+1], input[2*pos+2]);
    
}


int rmq(vector<int>segTree, int qLow, int qHigh, int low, int high, int pos) {
    
    //total overlap between the range and query
    if(qLow < low && qHigh >= high) {
        return segTree[pos];
    }
    
    //no overlap between the range and the query
    if(qLow > high && qHigh < low) {
        return INT_MAX;
    }
    
    int mid = (low + high) /2;
    
    return min(rmq(segTree,qLow, qHigh, low, mid, 2*pos+1),
               rmq(segTree, qLow, qHigh, mid+1, high, 2*pos+2));
    
    
    
}


int main()
{
    int N;
    cin >> N;
    
    vector<int> array(N);
    for(int i = 0 ; i < N+1; i++)
        cin >> array[i];
    
    vector<int> segTree(4*N); //take max possible value for now
    
    constructSegTree(array,segTree,0,N,0);
    
    int Q;
    cin >> Q;
    while(Q--) {
        
        int start, end;
        cin >> start >> end;
        cout << rmq(segTree,start,end,0,N,0);
    }
    
    return 0;
    
}
