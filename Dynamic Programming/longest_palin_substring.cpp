#include <iostream>
#include <vector>
#include <string>
#include <algorithm>




std::string LongestPalindromeSubString(std::string input) {
	
	if(input.empty()) return "";
	//create a matrix of [input.length()][input.length()]
	int len = input.length();

	std::vector<std::vector<int> > mat(len, std::vector<int>(len));

	std::string answer;

	//single character is palindrome of itself.
	for(int i = 0 ; i < len; i++){
		mat[i][i] = 1;
	}

	int max_length = 1;
	int startIndex = 0;
	for(int i = 0 ; i < len-1; i++) {
		if(input[i] == input[i+1]) {
			mat[i][i+1] = 1;
			max_length = 2;
			startIndex = i;
		}
	}

	for(int le = 3; le  <= len; le++) {

		for(int i = 0; i < len-le+1; i++) {
			int j = i + le -1;

			//mat[i+1][j-1] == 1 this beacause the previous was substring
			if((mat[i+1][j-1] == 1) && input[i] == input[j]){
				mat[i][j] = 1;

				if( le > max_length) {
					max_length = le;
					startIndex = i;
				}
			}

		}

	}

	for(int i = startIndex; i <= startIndex + max_length -1; i++) {
		answer += input[i];
	}

	return answer;

}

int main(){

	std::string inputStr;
	std::cin>>inputStr;

	std::cout << LongestPalindromeSubString(inputStr) << "\n";

	return 0;

}