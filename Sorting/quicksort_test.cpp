#include<iostream>
#include<vector>
using namespace std;


void partition(vector<int> arr )
{

	int no = arr.size();
	cout<<"Length of array : "<<no<<endl;
	int pivot = arr[0];
	
	int i = 1;
	int j = no;
	
	for(int k = 0 ; k < no ; k++ )
	{
		
			while( arr[i] < pivot )
			{
				i++;
				
			}
			cout<<"arr[i] : "<<arr[i]<<endl;
			int temp  = arr[i];
			arr[i] = pivot;
			pivot = temp;
			
			while( arr[j] > pivot )
				j--;
				
			cout<<"arr[j] : "<<arr[j]<<endl;
			int temp2  = arr[j];
			arr[j] = pivot;
			pivot = temp2;
		
	}
	
	
	for(int k = 0 ; k < no ; k++ )
		cout<<arr[k]<<" ";
		
	cout<<endl;
	

}


int main()
{
	vector<int> unsorted;
	unsorted.push_back(4);
	unsorted.push_back(5);
	unsorted.push_back(3);
	unsorted.push_back(7);
	unsorted.push_back(2);
	
	partition(unsorted);
	
	return 0;
	
	

}
