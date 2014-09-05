
#include<iostream>
#include<string>
using namespace std;


int main()
{
	string input;
	getline(cin,input);
	int count = 1;
	int j = 0;
	int k = 0;
	const char *ins = input.c_str();
	int l = 0 ;
	for(; ins[l] != '\0' ;l++);

	char *in = new char[l];
	
	for(int i = 0 ; i < l ; i++ )
		in[i] = ins[i];

	cout<<"compressed string is : "<<endl;
	for(int i = j ; i < l;)
	{
			while( in[j] == in[++i] )
				count++;
			if( count == 0 || count == 1)
			{
				in[k++] = in[j];
				//cout<<in[j];
			}
			 
			else
			{
				in[k++] = in[j];
				in[k++] = '0'+ (char)count;//only works if the number of characters is less than 10, since we dont have the ascii characters defined for more than 9
				//cout<<in[j]<<count;
			}
			count = 1;
			j = i;
	}

	for(int i = 0 ; i < k ; i++ )
		cout<<in[i];

	cout<<endl;

	return 0;
}


