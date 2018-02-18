#include <iostream>
#include <vector>
using namespace std;


int getMiddleElement(vector<int> numbers, int N) {
    
    int start = 0;
    int end = N-1;
    int middle = N/2;
    int result = 0;
    while(true) {
        
        if(numbers[middle] < numbers[start]) {
            middle--;
           
        }
        else if(numbers[middle] > numbers[end]) {
            middle++;
            
        }
        else if(numbers[middle] > numbers[start] && numbers[middle] < numbers[end])
        {
            start++;
            end--;
            result = numbers[middle];
        }
        else {
            start++;
            end--;
        }
        if(start >= middle || end <= middle) break;
        
    }
    return result;
    
}

int main() {
    int N;
    cin >> N;
    vector<int> n(N);
    for(int i = 0; i < N; i++)
        cin >> n[i];
    
    cout << getMiddleElement(n, N) << "\n";
    
    return 0;
}

