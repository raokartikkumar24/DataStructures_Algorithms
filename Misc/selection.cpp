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

	int i , j;
	int min,temp;
	for(i = 0 ; i < num-1 ; i++ )
	{
		min = i;//choose a minimum element
		for(j = i+1; j < num ;j++)
		{
			if( ele[j] < ele[min] )
			{
				min = j;
			}
		}
		temp = ele[min];
		ele[min] = ele[i];
		ele[i] = temp;
		
	}

	cout<<"Sorted elements are "<<endl;
	for(int i = 0 ; i< num ; i++)
		cout<<ele[i]<<" ";
		

}
