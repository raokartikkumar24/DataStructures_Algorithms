#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void intersection(string str1, string str2)
{
	string inter;
    std::set_union(str1.begin(),str1.end(),str2.begin(),str2.end(),std::back_inserter(inter));
	
	cout<<inter<<endl;
		
}


int main()
{
	string str1,str2;
	getline(cin,str1);
	getline(cin,str2);
	intersection(str1,str2);
	return 0;
}
