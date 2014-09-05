#include<iostream>
#include<map>
#include<string>
#include<stdlib.h>
#define HASH_SIZE 1500
#define HASH_MOD 1007

using namespace std;

int hashFunction(string value)
{
	const char *str = value.c_str();
	int i = 0;
	int key = 1;
	for(; str[i] != '\0';i++);

	for(int j = 0 ; j < i-1 ; j++)
	{
		key*=(int)(str[j]);
	}
	
	return key%HASH_MOD;	

return 1;
}

int main()
{
	string input;
	getline(cin,input);
	cout<<hashFunction(input)<<endl;
	return 0;
}
