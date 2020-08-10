#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int r = obstacleGrid.size();
        int c = obstacleGrid[0].size();
        
        if(obstacleGrid[0][0] == 1) return 0;
        
        obstacleGrid[0][0] = 1;
        
        for(int i = 1; i < r; i++) {
            obstacleGrid[i][0] = (obstacleGrid[i][0] == 0 && obstacleGrid[i-1][0] == 1 ? 1 : 0);
        }
        
         for(int i = 1; i < c; i++) {
            obstacleGrid[0][i] = (obstacleGrid[0][i] == 0 && obstacleGrid[0][i-1] == 1 ? 1 : 0);
        }
        
        
        for(int i = 1 ; i < r; i++) {
            for(int j  = 1 ; j < c; j++) {            
                    if( obstacleGrid[i][j] == 1) {
                         obstacleGrid[i][j] = 0;
                    } 
                    else {
                             obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
                        }
                }
            }
        
        return obstacleGrid[r-1][c-1];
        
    }
};
int main()
{
    
    Solution sol;

    int m, n ;
    cin>> m >> n;

    cout << sol.uniquePathsWithObstacles(m,n);

    return 0;
}