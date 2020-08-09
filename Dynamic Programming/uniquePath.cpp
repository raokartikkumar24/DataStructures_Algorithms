#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> matrix(m, vector<int>(n));
        
        for(int i = 0 ; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i==0 || j == 0) { // For only row or column there is only one way
                    matrix[i][j] = 1;
                }
                else {
                //else its sum of paths taken from left and above cell
                    matrix[i][j] = matrix[i-1][j] + matrix[i][j-1];
                }
            }
        }
        
        return matrix[m-1][n-1];
        
    }
};

int main()
{
    
    Solution sol;

    int m, n ;
    cin>> m >> n;

    cout << sol.uniquePaths(m,n);

    return 0;
}