#include<iostream>
#include<string>
using namespace std;

bool uniqueString(string inputString)
{
	int l = inputString.size();
	int mid = l/2;
	for(int i = 0 , j = l-1;  i < mid , j > mid+1 ; i++, j--)
	{
		if( inputString[i] ^ inputString[j] )
			return false;
			
		else
				return true;
	}
	
	return true;
		
}

int main()
{
	string  csinput;
	getline(cin,csinput);
	
	cout<<(csinput[0] ^ csinput[1])<<endl;
	
	if( uniqueString( csinput ) )
		cout<<"Not unique"<<endl;
	else
		cout<<"Unique"<<endl;
	
}