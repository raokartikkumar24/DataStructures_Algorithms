#include <iostream>
#include <vector>
#include <string>
#include <algorithm>



int LongestPalindromeSubsequence(std::string input) {
	
	//create a matrix of [input.length()][input.length()]
	int len = input.length();

	std::vector<std::vector<int> > mat(len, std::vector<int>(len));


	//single character is palindrome of itself.
	for(int i = 0 ; i < len; i++){
		mat[i][i] = 1;
	}

	for(int le = 2; le  <= len; le++) {

		for(int i = 0; i < len-le+1; i++) {
			int j = i + le -1;

			if(le == 2 && input[i] == input[j]) {
				mat[i][j] = 2;
			}

			if(input[i] == input[j]) {

				//2 because lenght of matched characters is 2 input[i] + input[j]
				//+ the already matched strings at i+1, j-1 location
				mat[i][j] = 2 + mat[i+1][j-1];

			}
			else {
				//If there is substring which is palindrome then pick that 
				//this will help in getting the correct value for larger lengths
				mat[i][j] = std::max(mat[i][j-1], mat[i+1][j]);
			}

		}

	}

	for(int i = 0 ; i < len; i++) {
		for(int j = 0; j < len; j++) {
			std::cout << mat[i][j] << "\t";
		}
		std::cout << "\n";
	}

	return mat[0][len-1];

}

int main(){

	std::string inputStr;
	std::cin>>inputStr;

	std::cout << LongestPalindromeSubsequence(inputStr) << "\n";

	return 0;

}