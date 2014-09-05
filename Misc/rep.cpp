#include<iostream>

using namespace std;

int main()
{
	int arr[] = {1,1,1,1,1,1,2,2,3,3,4,4,4,4,4,5};
	
	int i = 0;
	int max =0;
	int num = 0;
	int thenum;
	int j=0;
	for(;i<16;)
	{
		int count = 0 ;
		j = i + 1;
		while( arr[i] == arr[j++] )
		{
			count++;
			num = arr[i];
		}
		//cout<<endl<<"j : "<<j<<endl;
		i = j-1;
		//cout<<endl<<"Count : "<<count<<endl;
		if( count > max ) {
			max = count;
			thenum = num;
			}
	
	}
	
	cout<<thenum<<" repeats "<<max+1<<" times"<<endl;
	
	return 0;
	
}