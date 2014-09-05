#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s1= "karthik";
	s1[5] = 'f';
	
	string s2("rao");
	
	s2[2] = 'w';
	
	cout<<endl<<s1<<endl<<s2<<endl;
	
	return 0;
}