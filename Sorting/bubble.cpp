#include<iostream>
using namespace std;

int main()
{
	int num;
	cout<<"Insert # of elements : ";
	cin>>num;
	int *ele = new int[num];
	for(int k = 0 ; k < num ;k++)
		cin>>ele[k];

	cout<<"un-Sorted elements are "<<endl;
	for(int i = 0 ; i< num ; i++)
		cout<<ele[i]<<" ";

	cout<<endl;
	int i,j;
	for(i = 0 ; i < num ; i++) {
		for(j =0 ; j < num-1; j++) {
		if( ele[j] > ele[j+1] )
		{
			int temp = ele[j];
			ele[j] = ele[j+1];
			ele[j+1] = temp;
		}
	}
	
   }
		
	cout<<"Sorted elements are "<<endl;
	for(int i = 0 ; i< num ; i++)
		cout<<ele[i]<<" ";
	cout<<endl;
		
	
}
