#include<iostream>
using namespace std;


void swap(int a[],int i, int j)
{
	int temp ;
	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}
void quicksort(int a[], int l, int r)
{
	int i = l;
	int j = r-1;
	int pivot = (i+j)/2;
	while ( i < j ) {
		
		while( a[++i] < a[pivot] ) if( i == pivot ) break;
		while( a[--j] > a[pivot] ) if( j == pivot ) break;
		
		swap(a,i,j);
    }
	
	swap(a,i,pivot);
	
	
	
}

int main()
{
	int arr[] = { 12,3 ,4, 55,67,66,89,10,100,8};
	quicksort(arr,0,10);
	
	return 0;
}