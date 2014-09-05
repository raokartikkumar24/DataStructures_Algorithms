#include<iostream>
using namespace std;

int val = 10000;
void GetRepeatedNumber(int ele[])
{
	for(int i = 0; i<val;i++)
	{
		int v = ele[i];
		if( v > 0 )
			ele[i] = v*-1;
		
		if( ele[v] < 0)
			{
				cout<<"The repeated number is "<<v<<" repeating at "<<i+1<<" location"<<endl;
			}
			
		//cout<<endl<<ele[i]<<endl;
	}
}

int main()
{
	int *num = new int[val];
	
	
	
	for(int i = 0 ; i < val ; i++)
		num[i] = i+1;
	
	
	num[1411] = 190;
	
	GetRepeatedNumber(num);
	
	/*for(int i = 0 ; i < val ; i++)
		cout<<num[i]<<" ";*/
	
	
	//int sum  = 0 ;
	
	//for(int i = 0 ;  i < val ; i++)
		//sum+=num[i];
		
	
	//cout<<"Sum is : "<<sum<<endl;
	
	//cout<<"Actual sum is : "<<((val * ( val + 1 ) )/2)<<endl;
	
	//int ac = ((val * ( val + 1 ) )/2);
	
	//cout<<"The repeated number is : " << ac - sum<<endl;
	
	
	return 0;

}
