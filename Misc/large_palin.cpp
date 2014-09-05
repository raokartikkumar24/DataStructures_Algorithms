#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
map<int,string> mapStrings;

string reverse(string streverse)
{
	int len = streverse.length();
	char *arr = new char[len+1];
	int j = 0;
	for(int i = len-1 ;i >=0 ; i--,j++)
		arr[j] = streverse.at(i);
	string revstr( arr );
	return revstr;
}

bool ispalin(string str)
{
	if( str.length() == 1 ) return false;
	string s = reverse(str);
	if( s == str) return true;
	else return false;

}

void generateSubstrings(string originalString)
{
	int l = originalString.length();
	for(int i = 0 ; i < l; i++)
	{
		char *substr = new char[l-i];
		
		originalString.copy(substr,l-i,i);
		//if( ispalin(substr) )
			mapStrings[l-i] = substr;
		
		originalString.copy(substr,l-i,0);
		//if( ispalin(substr) )
			mapStrings[l-i] = substr;
		
		originalString.copy(substr,l-i-i,i);
		//if( ispalin(substr) )
			mapStrings[l-i] = substr;

	}

	/*for(int i = 0 ; i < l-1 ;i++)
	{
		char *substr = new char[l-i];
		originalString.copy(substr,l-i,0);
		if( ispalin(substr) )
			mapStrings[l-i] = substr;
		
	}

	for(int i = 0 ; i < l-1 ;i++)
	{
		char *substr = new char[l-i];
		originalString.copy(substr,l-i-i,i);
		if( ispalin(substr) )
			mapStrings[l-i-i] = substr;
		
	}*/
	cout<<"Substrings are :"<<endl;
	map<int,string>::iterator it = mapStrings.begin();
	for(; it != mapStrings.end(); it++)
		cout<<it->second<<endl;

	if( mapStrings.size() > 0 )
	{
		map<int,string>::reverse_iterator en = mapStrings.rbegin();

		cout<<"The largest Palindrome in the string is : "<<(*en).second<<endl;
	}

	else cout<<"No palindromes"<<endl;//either this or print each character in the string i.e each character is a palindrome!
			
}

int main()
{
	string str;
	getline(cin,str);
	
	generateSubstrings(str);

return 0;
} 
