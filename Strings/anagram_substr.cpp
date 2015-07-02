/**
	Given two strings s1 and s2, check if any substring of s1 is an anagram of s2
	
**/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	string s1, s2;
	cin >> s1 >> s2;

	if (s1.length() < s2.length())
		cout << "Not found \n";
	else
	{
		int a1[26] = { 0 };
		int a2[26] = { 0 };
		bool found = false;

		for (int i = 0; i < s2.length(); ++i)
			a2[s2[i] - 'a']++;

		int substrsum = 0;

		for (int i = 0; i < 26; ++i)
			substrsum += a2[i];

		//cout << "substring : " << substrsum << "\n";

		int j = 0;
		for (j = 0; j < s1.length();)
		{
			int x = 0;
			for (int k = j; x < s2.length(); ++k, ++x)
			{
				//TODO : bound check for k
				//if (k >= j) break;
				a1[s1[k] - 'a']++;

			}
			
			int val = 0;
			for (int p = 0; p < 26; ++p) {
				if ((a1[p] == a2[p]) && a1[p] != 0 && a2[p] != 0) {
					val += a2[p];
				}
			}
			
			//cout << "val : " << val << endl;
			if (substrsum == val)
			{
				found = true;
				break;
			}
			else
			{
				j++;
				memset(a1, 0, sizeof(a1));
			}
		

		}

		if (found) cout << "Found!! \n";
		else cout << "Not found!! \n ";


	}

	return 0;
}