#include<iostream>
#include<string>
using namespace std;

bool IsAnagram(string s1, string s2)
{
	if( s1.length() != s2.length() ) return false;
	
	int arr[26] = {0};
	
	for(int i = 0 ; i < s1.length(); i++)
	{
		arr[s1[i]-'a']++;
	}
	
	for(int i = 0 ; i < s2.length(); i++)
	{
		arr[s2[i]-'a']--;
	}
	//for(int i = 0 ; i < 26; i++) cout<<arr[i]<<" ";
	
	cout<<endl;
	
	for(int i = 0 ; i < 26; i++) {
		if( arr[i] != 0 ) return false;
	}
	
	return true;
		
	
}

int main()
{
	string str1,str2;
	getline(cin,str1);
	getline(cin,str2);
	bool res = IsAnagram(str1,str2);
	if( res ) cout<<"ANAGRAM!!"<<endl;
	else cout<<"NOT AN ANAGRAM!!"<<endl;
	return 0;
}