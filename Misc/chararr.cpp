#include<iostream>
using namespace std;

int main()
{
	int alpha[26];
	for(int q = 0 ; q < 26 ; q++ )
		alpha[q] = 1;

	char input[] = "aaaaaaaaabaabaabcdefffffffffffghiiijklmnopqrstuvwxyzzz";
	int length = 0;
	for(;input[length] != '\0' ; length++);
	int i,j;
	for( i = 0 , j = 1; i < length ; i++ )
	{
		for( j = i + 1 ; j < length ; j++ )
		{
			if( input[i] == input[j] )
			{
				 alpha[input[i] - 'a'] += 1;
				 //j++;
			}
		}	
	}

	for(int s = 0 ; s < 26 ; s++ ) {cout<<alpha[s]<<" ";}
	cout<<endl;

	return 0;
}
