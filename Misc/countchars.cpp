#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

int main()
{
string csinput;
cout<<"Enter the sentence : "<<endl;
getline(cin,csinput);

char *str = new char[csinput.length() + 1];

strcpy(str, csinput.c_str());

int alpha[26] = {0};
int c = 0;
for(int i = 0 ; i < strlen(str); i++ )
{
	if( str[i] != ' ')	
		alpha[str[i] - 'a']++;
}


for(int i = 0 ; i < 26 ;i++)
{

	cout<<"Count of "<<(char)('a' + i)<<" is "<<alpha[i]<<endl;
}

return 0;
}
