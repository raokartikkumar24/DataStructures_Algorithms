#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int main()
{

	//char arr[] = "kartikkumar kumblebalkrishna rao";

	char arr[10];

	//getline(cin,arr[0]);

	gets(arr);

	int len =0;
	for(;arr[len]!='\0';len++);

	int i = 0,j=len-1;

	int mid = len/2;

	for(;i < mid-1,j>mid;i++,j--)
	{
		arr[i] = arr[i]^arr[j];
		arr[j] = arr[i]^arr[j];
		arr[i] = arr[i]^arr[j];
	}


	for(int p = 0 ; p < len ;p++) cout<<arr[p];

	cout<<endl;

return 0;	
}
