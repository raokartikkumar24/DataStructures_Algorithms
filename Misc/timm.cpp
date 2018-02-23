//
//  tim.cpp
//  jjj
//
//  Created by krao4 on 23/02/18.
//  Copyright © 2018 krao4. All rights reserved.
//

// you can use includes, for example:
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
string solution(int A, int B, int C, int D, int E, int F) {
    int array[6] = { A, B, C, D, E , F };
    std::sort(array, array+6);
    
    if(array[0] > 2 || array[1] > 3) return "NOT POSSIBLE";
    
    std::string result;
    
    int i = 0;
    for(; i < 6; i++) {
        
        if(i == 0) {
            if(array[i] < 3) {
                result += std::to_string(array[i]);
            }
            else {
                cout << "Reached here!! \n";
            }
        }
        
        else if(i == 1) {
            if(array[i] < 4) {
                result += std::to_string(array[i]);
                result += ":";
            }
            else {
                std::swap(array[i],array[i-1]);
                result += std::to_string(array[i]);
            }
        }
        
        else if(i == 2 || i == 4) {
            if(array[i] < 6) {
                result += std::to_string(array[i]);
            }
            else {
                std::swap(array[i],array[i-1]);
                result += std::to_string(array[i]);
            }
        }
        
        else if(i == 3 || i == 5) {
            if(array[i] <=9 ) {
                result += std::to_string(array[i]);
                if(i != 5) result += ":";
            }
            else {
                std::swap(array[i],array[i-1]);
                result += std::to_string(array[i]);
            }
        }
        
        
    }
    return result;
    
}

int main() {
    int a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;
    cout << solution(a,b,c,d,e,f) << endl;
    return 0;
}

