#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	long long n;
	int k;
	cin>>n>>k;

	long long powr = pow(n,n);
	cout<<powr<<endl;
	long *arr = new long[100];
	int i = 0;
	int quo;
	while( (powr / 10) != 0 )
	{
		arr[i] = powr%10;//remainder
		powr = powr/10;
		quo = powr/10;
		cout<<"powr after dividing "<<powr<<endl;
		i++;
	}
	i++;
	arr[i] = quo;	
	int len = i;
	cout<<"Length is :"<<len<<endl;
	
 	for(int j = 0 ; j < len ;j++)
		cout<<arr[j]<<" ";
	
	cout<<endl;
        

return 0;
	
	
	
}
