/**
 Program to return the column name for a index in a excel sheet
 For example 1 : A, 705: AAC, 28 : AB
 **/
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string getColumnName(int index) {

	char array[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' , 'I' ,'J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	
	int number = index;
	string concat = "";
	while(number > 0) {
		

		int rem = number % 26;

		if(rem == 0) {
			concat += 'Z';
			number = (number/26) - 1;
		}
		
		else {
			concat += array[(number%26)-1];
			number /= 26;
	        }
	}

    reverse(concat.begin(), concat.end());
	return concat;

}

int main() {

	int index = 0;
	cin >> index;

	cout << getColumnName(index) << "\n";

	return 0;
}
