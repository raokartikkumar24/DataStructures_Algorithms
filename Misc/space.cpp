#include<iostream>
using namespace std;
int main()
{
	char *in = new char;
	
	gets(in);
	int l=0;
	for(;in[l]!='\0';l++);
	
	for(int i = 0 ; i < l ; i++ )
	{
		if(in[i] == ' ') cout<<"%20";
		else cout<<in[i];
	}
		
	cout<<endl;
	
	int a[2] = {1,2};
	cout<<sizeof(a[0])<<endl;
	
	return 0;
	
}