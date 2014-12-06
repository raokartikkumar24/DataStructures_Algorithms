#include<iostream>

using namespace std;

int main()
{
char a = 'k',b='o';

cout<<"before the operation : "<<a<<" "<<b<<endl;
a = a ^ b;

b = a ^ b;

a = a ^ b;

cout<<"After the operation : "<<a<< " " <<b<<endl;


char arr[] = "my name is shashikala";
int len = 0; 
for(; arr[len] != '\0';len++);
cout<<"length is : "<<len<<endl;
int i = 0, j = len-1;
int mid = len/2;

for(int p = 0 ; p < len; p++)
	cout<<arr[p];
cout<<endl;

for(;i < mid, j > mid;i++,j--)
{
	arr[i] = arr[i] ^ arr[j];
	
	arr[j] = arr[i] ^ arr[j];
	
	arr[i] = arr[i] ^ arr[j];
}

for(int p = 0 ; p < len; p++)
	cout<<arr[p];
	
cout<<endl;

return 0;

}