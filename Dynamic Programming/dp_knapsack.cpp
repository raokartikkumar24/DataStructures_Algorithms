#include <iostream>


using namespace std;

//TODO : get the corresponding weights

int getMaxValues(int weight[], int value[],int capacity, int n) {
    
    int knapsack[n+1][capacity+1];
    
    
    
    for(int i = 0; i < n+1; i++)
        knapsack[i][0] = 0;
    for(int i = 0 ; i< capacity+1; i++)
        knapsack[0][i] = 0;
    
    
    for(int i = 1 ; i < n+1; i++)
    {
        for(int j = 1 ; j < capacity+1; j++)
        {
            //if the capacity is less than the weight, pick the previous weight
            if(j < weight[i-1])
                knapsack[i][j] = knapsack[i-1][j];
            else
            {
                //maximum between
                /*
                 1. pick the weight(value) and the value of remaining weight
                 2. dont pick the current so it will be whatever was picked previously
                 */
                knapsack[i][j] = max(value[i-1] + knapsack[i-1][j-weight[i-1]], knapsack[i-1][j]);
            }
        }
    }
    
    for(int i = 0 ; i < n+1 ; i++)
    {
        for(int j = 0; j < capacity+1; j++)
            cout << knapsack[i][j] << " ";
        cout << "\n";
    }
    
    
    return knapsack[n][capacity];
}

int main()
{
    
    int items,c;
    cin >> items >> c;
    int w[items], v[items];
    for(int i = 0 ; i < items; i++)
        cin >> w[i];
    
    for(int i = 0 ; i < items; i++)
        cin >> v[i];
    
    cout << getMaxValues(w,v,c,items) << endl;
    
    return 0;
    
    
}


