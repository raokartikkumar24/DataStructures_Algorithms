/**
 remove repeating consective characters for example : aaabbbccdaa --> abcda
 **/

#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;


string removeRepeatingCharactersStack(string in, int n) {
    stack<char> st;
    
    for(int i = 0 ; i < n ; i++) {
        if(st.empty()) {
            st.push(in[i]);
        }
        else {
            if(in[i] != st.top())
                st.push(in[i]);
        }
    }
    
    char result[st.size()+1] ;
    result[st.size()] = 0x0;
    int j = (int)st.size()-1;
    while(!st.empty()) {
        char c = st.top();
        st.pop();
        result[j] = c;
        j--;
    }
    string result2(result);
    return result2;
    
}


string removeRepeatingCharacters(string in, int n) {
    int i = 0;
    int j = 0;
    string result;
    while(i < n) {
        result += in[i];
        j = i+1;
        while(in[i] == in[j])
            j++;
        i = j;
    }
    
    return result;
    
}


int main()
{
    int N;
    cin >> N;
    
    string input;
    cin >> input;
    cout << "Time" << "\t" << "Space" << "\t" << "Output \n";
    cout << "O(n)" << "\t" << "O(1)" << "\t" << removeRepeatingCharacters(input,N) << "\n";
    cout << "O(n)" << "\t" << "O(n)" << "\t" << removeRepeatingCharactersStack(input,N) << "\n";
    
    return 0;
    
}


