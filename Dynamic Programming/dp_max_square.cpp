/**
 Largest square matrix in given matrix of 0s and 1s
 **/


#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    
    int matrix[6][5] ;
    for(int i = 0 ; i < 6; i++) {
        for(int j = 0 ; j < 5; j++) {
            cin >> matrix[i][j];
        }
    }
    
    int sumMatrix[6][5];
    
    for(int i = 0 ; i < 5; i++)
        sumMatrix[0][i] = matrix[0][i];
    
    for(int i = 0 ; i < 6; i++)
        sumMatrix[i][0] = matrix[i][0];
    
    for(int i = 1; i < 6; i++) {
        for(int j = 1; j < 5; j++) {
            
            if(matrix[i][j] == 1)
                sumMatrix[i][j] = min(matrix[i-1][j], min(matrix[i][j-1], matrix[i-1][j-1])) + 1;
            else
                sumMatrix[i][j] = 0;
            
        }
    }
    
    int max_i = 0, max_j = 0;
    int max_sum = sumMatrix[0][0];
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 5; j++) {
            if(max_sum < sumMatrix[i][j]){
                max_sum = sumMatrix[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }
    
    for(int i = max_i ; i > max_i - max_sum ; i--){
        for(int j = max_j; j > max_j - max_sum; j--) {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
    
}

