#include <iostream>
#include <stack>
#include <vector>

using namespace std;


int getLargestRectangleFromHistogram(int hist[], int N) {
    
    int i = 0;
    int maxArea = 0;
    stack<int> s;
    int area = 0;
    while( i < N )
    {
        
        if (s.empty() || hist[i] >= hist[s.top()]) {
            s.push(i);i++;
        }
        
        else
        {
            int topelement = s.top();
            s.pop();
            area = hist[topelement] * (s.empty() ? i : i - s.top() - 1);
            
            if (area > maxArea)
                maxArea = area;
        }
    }
    
    while (!s.empty())
    {
        int topelement = s.top();
        s.pop();
        
        area = hist[topelement] * (s.empty() ? i : i - s.top() - 1);
        
        if (area > maxArea)
            maxArea = area;
        
    }
    return maxArea;
    
}

int main()
{
    
    int rows,cols;
    cin >> rows >> cols;
    int matrix[rows][cols];
    
    for(int i = 0; i < rows; i++) {
        for(int j = 0 ; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
    
    int normalArray[cols];
    for(int i = 0 ; i < cols; i++)
        normalArray[i] = 0;
    
    int maxRectangleArea = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0 ; j < cols; j++) {
            if(matrix[i][j] == 0) {
                normalArray[j] = 0;
            }
            else {
                normalArray[j] += matrix[i][j];
            }
        }
        int maxColumArea = getLargestRectangleFromHistogram(normalArray,cols);
        if(maxRectangleArea < maxColumArea) {
            maxRectangleArea = maxColumArea;
        }
    }
    
    cout << maxRectangleArea << "\n";
    
    
    
    return 0;
}

