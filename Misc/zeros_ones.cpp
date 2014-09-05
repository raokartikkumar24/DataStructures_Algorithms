#include<iostream>
using namespace std;

int bsearch(int arr[], int start, int end)
{
	int mid = (start+end)/2;
	int pos;
	if( arr[mid] == 1 && arr[mid-1] == 0) return mid+1;

	else if ( arr[mid-1] == 1 )
		pos = bsearch(arr,0,mid);
	else
		pos = bsearch(arr,mid+1,end);

	return pos;
}

int bestcase(int arr[], int start, int end)
{
	if( arr[start] == 1 ) return 1;
	
	else if ( arr[end] == 1 && arr[end-1] == 0 ) return end;	
	
	else
	  bsearch(arr,0,end);
}

int main()
{
	//TODO: Modify the size!
	int ar[] = {0,0,0,0,0,0,0,0,1};
	int i = 0 ;

	cout<<"Position is : "<<bsearch(ar,0,9)<<endl;
	return 0;
}
