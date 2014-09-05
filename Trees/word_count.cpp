#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<fstream>
using namespace std;

int main()
{
	ifstream in("words.txt");
	string csinput;
	int c = 1;
	map<string,int> mapOfStrings;
	while( !in.eof() )
	{
		in>>csinput;
		c=1;
		if( mapOfStrings[csinput] > 0) {
			mapOfStrings[csinput] = ++c;
		}
		
		else mapOfStrings[csinput] = 1;


	}
	
	
	map<string,int>::iterator it = mapOfStrings.begin();
	for(; it != mapOfStrings.end(); it++)
		cout<<(*it).first<<" : "<<(*it).second<<endl;

	return 0;

	

}
