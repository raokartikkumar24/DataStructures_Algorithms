#include <iostream>
#include <string>

using namespace std;

int main()
{

	string input;
	getline(cin,input);

	int len = input.length();

	//cout << len << "\n" ;

	int indexLast = len - 1;
	int indexFront = len - 1;

	int i = 0;

	for(; indexLast >= 0; )
	{
		int spaceIndex = 0;
		while(input[indexFront] != ' ' && indexFront > -1) 
		{
			indexFront--;
			
		}
		spaceIndex = indexFront;
		//cout << "Space : " << spaceIndex << " "  ;
		indexFront++;
		//reached a space
		while(indexFront <= indexLast)
		{
			cout << input[indexFront];
			indexFront++;
		}
		cout << " ";

		indexFront = spaceIndex - 1;
		indexLast = spaceIndex -1;
		

	}
	cout << endl;
	return 0;
}

