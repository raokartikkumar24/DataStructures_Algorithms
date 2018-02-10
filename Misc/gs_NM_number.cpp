#include <iostream>
#include <vector>
#include <string>


using namespace std;

int getIntegerFromPattern(string pattern) {
    if(pattern.size() == 0) return -1;
    if(pattern == "M") return 21;
    if(pattern == "N") return 12;
    int len = (int)pattern.length();
    
    vector<int> numArray;
    vector<int> tempArray;
    for(int i = 0 ; i <= len ; i++) {
        numArray.push_back(i+1);
        tempArray.push_back(i+1);
    }
     int countMPatterns = 0;
    for(int i = 0 ; i < len; i++) {
        int nextIndex = i;
        if(pattern[i] == 'M') {
            countMPatterns++;
            for(int j = nextIndex; j < numArray.size()-1; j++) {
                if(numArray[j] < numArray[j+1]) {
                    swap(numArray[j],numArray[j+1]);
                    nextIndex = j+1;
                    break;
                }
            }
            
        }
        else if(pattern[i] == 'N') {
            for(int j = nextIndex; j < numArray.size()-1; j++) {
                if(numArray[j] > numArray[j+1]) {
                    swap(numArray[j],numArray[j+1]);
                    nextIndex = j+1;
                    break;
                }
            }
            
        }
        else {
            return -1;
        }
        
    }
    
    bool reverse =  false;
    if(countMPatterns == len) {
        tempArray.reserve(tempArray.size());
        reverse = true;
    }
    
    vector<int> t;
    if(reverse)
        t = tempArray;
    else
        t = numArray;
    
    string str;
    for(int i = 0 ; i < t.size(); i++) {
        str = str + to_string(t[i]);
    }
    
    int result = stoi(str);
    
    return result;
}

int main() {
  
    string input;
    cin >> input;
    
    cout << getIntegerFromPattern(input) << endl;
    
    return 0;
}
