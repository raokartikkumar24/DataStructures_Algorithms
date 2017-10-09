#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;


int main() {

    stack<int> st1;
    stack<int> st2;
    int tc;
    cin >> tc;
    while(tc--){
        int n,value;
        cin >> n;
        if(n == 1){
            cin >> value;
            st1.push(value);
//            if(st1.empty() && st2.empty()){
//                st1.push(value);
//            }
//            else {
//                if(st2.empty()){
//                    while(!st1.empty()){
//                        st2.push(st1.top());
//                        st1.pop();
//                    }
//                    st2.push(value);
//                }
//                else if(st1.empty()){
//                    while(!st2.empty()){
//                        st1.push(st2.top());
//                        st2.pop();
//                    }
//                    st1.push(value);
//                    while(!st1.empty()){
//                        st2.push(st1.top());
//                        st1.pop();
//                    }
//                }
//                else {
//                    //cout << " I dont know \n";
//                }
//            }
        }
        else if(n==2){
            
            if(st2.empty()){
                while (!st1.empty()) {
                    st2.push(st1.top());
                    st1.pop();
                }
                
                st2.pop();
            }
            
//            if(!st1.empty() && st2.empty()){
//                st1.pop();
//            }
//            else if(st1.empty() && !st2.empty()){
//                st2.pop();
//            }
        }
        else{
//            if(!st1.empty()){
//                cout << st1.top() << "\n";
//            }
//            else {
//                cout << st2.top() << "\n";
//            }
            if(st2.empty()){
                while(!st1.empty()){
                    st2.push(st1.top());
                    st1.pop();
                }
            }
            cout << st2.top() << "\n";
        }
        
    }
    return 0;
}

