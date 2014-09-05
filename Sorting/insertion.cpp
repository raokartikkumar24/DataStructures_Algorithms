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

	int i,j,insertedElement;
	for(i = 0 ; i < num ; i++)
	{
		insertedElement = ele[i];
		j = i;
		while( ele[j-1] > insertedElement && j >= 1 )
		{
			//keep on moving the element until we find the correct position for that element.
			ele[j] = ele[j-1];j--;
		}
		ele[j] = insertedElement;
		
	}

	cout<<"Sorted elements are "<<endl;
	for(int i = 0 ; i< num ; i++)
		cout<<ele[i]<<" ";	
	return 0;
}
