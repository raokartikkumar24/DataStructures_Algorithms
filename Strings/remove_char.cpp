/*
*	Given a string  str and occurance i, remove the character that occured for ith time.
*	Example : aabbaa, 1 Output L aba
*   Example 2 : aabbaa, 5 Output aabbaa --> There is no character that occurs for 5th time
*
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;


void RemoveCharacters(string str, int occur);

int main()
{

	string input;
	cin >> input;

	int occr;
	cin >> occr;

	RemoveCharacters(input, occr);


}

void RemoveCharacters(string str, int occur)
{

	int len = str.length();
	int i = 0;
	string result = "";
	for (; i < len; )
	{
		int j = i + 1;
		string t = "";
		do
		{
			t += str[i];
			j++;

		} while (str[i] == str[j] && j < len);
		
		t += str[j - 1]; //copy the last matched character

		i = j;

		if (occur > t.length()) {
			for (int k = 0; k < t.length(); ++k)
				result += t[k];
		}
		else
		{
			for (int k = 0; k < t.length() - 1 ; ++k)
				result += t[k];
		}
	}

	cout << result << endl;


}