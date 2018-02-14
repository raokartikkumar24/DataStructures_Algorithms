/**
 Largest square matrix in given matrix of 0s and 1s
 **/


#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int rows, cols;
    cin >> rows >> cols;
    int matrix[rows][cols] ;
    for(int i = 0 ; i < rows; i++) {
        for(int j = 0 ; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
    
    int sumMatrix[rows][cols];
    
    for(int i = 0 ; i < cols; i++)
        sumMatrix[0][i] = matrix[0][i];
    
    for(int i = 0 ; i < rows; i++)
        sumMatrix[i][0] = matrix[i][0];
    
    for(int i = 1; i < rows; i++) {
        for(int j = 1; j < cols; j++) {
            
            if(matrix[i][j] == 1)
                sumMatrix[i][j] = min(sumMatrix[i-1][j], min(sumMatrix[i][j-1], sumMatrix[i-1][j-1])) + 1;
            else
                sumMatrix[i][j] = 0;
            
        }
    }
    
    
    //    for(int i = 0 ; i < rows; i++) {
    //        for(int j = 0 ; j < cols; j++)
    //            cout << sumMatrix[i][j] << "\t";
    //        cout << "\n";
    //    }
    
    int max_i = 0, max_j = 0;
    int max_sum = sumMatrix[0][0];
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
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
