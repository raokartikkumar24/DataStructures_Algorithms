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


	for(int i = 0 ; i < s1.length()+1; i++) {
		for(int j = 0 ; j < s2.length()+1; j++) {
			cout << matrix[i][j] << " ";
		} 
		cout << endl;
			
	}
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
