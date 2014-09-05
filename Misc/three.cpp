#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	
	string csInput;
	getline(cin,csInput);
	
	int l = csInput.size();
	int i=0,j;
	int tail = 0;
	for(;i<l;i++)
	{	
		j =1;
		for(;j<l;j++)
		{
			if( csInput[i] = csInput[j]) break;
		}
	}
	
	std::sort(csInput.begin(), csInput.end());
	
	cout<<csInput;
	
	return 0;
}