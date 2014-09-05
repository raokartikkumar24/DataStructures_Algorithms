#include<iostream>
#include<vector>
#define MAX 50
using namespace std;

void add(long a1[], long a2[] )
{
	vector<int> result(MAX+1);//For now..Need to determine dynamically
	int carry = 0;
	int sum = 0;
	int i;
	for( i = MAX-1; i >=0 ; i-- )
	{
		
		sum = a1[i]+a2[i];
		if( sum ) {
		//cout<<"sum : "<<sum<<" i : "<<i<<endl;
		result[i+1] = (carry + (sum%10));
		carry = sum/10;
		}
		
	}
	
	result[0] = carry;
	for(int j = 0 ; j < MAX ;j++)
	{
		
		if( result[j] )
		cout<<result[j];
	}
	cout<<endl;

}

int main()
{
	int s;
	cout<<"Enter size:";
	cin>>s;
	
	long a1[MAX] = {0};
	long a2[MAX] = {0};
	for(int i = 0; i < s ;i++)
		cin>>a1[i];
	for(int i = 0 ; i < s ;i++)
		cin>>a2[i];
		
	add(a1,a2);
	
	
	
	return 0;
	

}