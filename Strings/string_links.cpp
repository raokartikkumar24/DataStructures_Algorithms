#include <iostream>
#include <string>

using namespace std;

int main()
{

	string listOfString[] = {"cat", "dog", "tiger", "gum", "row", "mike", "work" };

	char lastLetter[7] , firstLetter[7];

	int i = 0 , j = 0;
	for( i = 0 ; i < 7; i++ )
	{
		string temp = listOfString[i];
		lastLetter[i] = temp[temp.length()-1];
		firstLetter[i] = temp[0];
	}

/*	for( i = 0 ; i < 7; i++)
	{
		cout << lastLetter[i] << " ";
		
		//cout << firstLetter[i] << " ";
	}
*/


	int count = 0;
	int minVal = 0;
	for(int k = 0 ; k < 7; k++) {
	for( i = 0 ; i < 7; )
	{
		char findMe = lastLetter[i];
		for(j = 0 ; j < 7 ; j++)
		{
			if( j > i )
			{
				if(findMe == firstLetter[j])
				{
					count++;
					//cout << listOfString[i] << endl;
					cout << listOfString[j] << endl;
					break;
				}
			}

		}
		i = j;
		minVal = min(minVal,count);
		count = 0;
		
	}
}


	cout << "smallest link is : " << minVal << endl;


return 0;
}
