#include <iostream>
#include <vector>
#include <string>

using namespace std;


int getLCS(string s1, string s2){
    
    vector<vector<int> > matrix(s1.length()+1, vector<int>(s2.length() + 1));
    for(int i = 0 ; i < s1.length()+1; i++) {
        for(int j = 0 ; j < s2.length()+1; j++) {
            if(i == 0 || j == 0) {
                matrix[i][j] = 0;
            }
            else if(s1[i] == s2[j]){
                matrix[i][j] = 1 + matrix[i-1][j-1];
            }
            else {
                matrix[i][j] = max(matrix[i-1][j], matrix[i][j-1]);
            }
        }
        
    }
    
    /*
     for(int i = 0 ; i < s1.length()+1; i++) {
     for(int j = 0 ; j < s2.length()+1; j++) {
     cout << matrix[i][j] << " ";
     }
     cout << endl;
     }*/
    
    int len = matrix[s1.length()][s2.length()];
    if(len == 0) return 0;
    vector<char> matched(len);
    int i = (int)s1.length();
    int j = (int)s2.length();
    int p = i-1;
    int q = j-1;
    while(p >=0 && q >= 0) {
        if(s1[p] == s2[q]){
            matched[--len] = s1[p];
            // cout << "match for char " << s1[p] << " " << p << " " << q << "\n";
            i--;j--;p--;q--;
        }
        else {
            if(matrix[i-1][j] == matrix[i][j]){
                i--; // go on top;
                p--;
            }
            else if(matrix[i][j-1] == matrix[i][j]){
                j--;
                q--;
            }
            else {
                i--;j--;
            }
        }
    }
    
    
    for(int i = 0 ; i < matched.size(); i++)
        cout << matched[i] << " ";
    cout << endl;
    return matrix[s1.length()][s2.length()];
    
    
}


int main(){
    
    string s1,s2; //this can be an array of integers as well
    cin >> s1 >> s2;
    
    int lcs = getLCS(s1,s2);
    
    cout << lcs << endl;
    
    
    return 0;
}


