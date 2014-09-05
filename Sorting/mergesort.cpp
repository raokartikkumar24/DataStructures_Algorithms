#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
using namespace std;

void sort(int a[], int aux[],int lo, int hi);
void merge(int a[], int aux[],int lo, int mid, int hi);
void sort(int a[], int length);
int arrlength = 0;

int main()
{	
	string csElements;
	ifstream mystream("num2.txt");

	int c = 0;
	while(!mystream.eof())
	{
		getline(mystream,csElements);
		c++;
	}
	cout<<"C = "<<c<<endl;
	mystream.close();
	int *ele = new int[c-1];
	int index = 0;
	mystream.open("num2.txt");
	while(!mystream.eof())
	{
		getline(mystream,csElements);
		int x = atoi(csElements.c_str());
		if( x == 0 ) break;//already read the final element from the file
		//cout<<"x =" <<x<<" ";
		ele[index++] = x;
	}


	mystream.close();
	cout<<endl;
	arrlength = c-1;
	/*cout<<"the elements to be sorted are "<<endl;
	for(int i = 0 ; i < arrlength ;i++)
		cout<<ele[i]<<" ";*/

	
	
	
	sort(ele,arrlength);

	cout<<"The sorted elements are"<<endl;
	for(int i = 0 ; i < arrlength ;i++)
		cout<<ele[i]<<" ";

	cout<<endl;
	return 0;
}
void sort(int a[], int length)
{
	//cout<<"Inside Sort"<<endl;
	int aux[length];
	int lo = 0, hi = length-1;
	sort(a, aux, lo, hi);

	
}

void sort(int a[],int aux[], int lo, int hi)
{
	//cout<<"Inside recursive sort"<<endl;
	if( lo < hi ) {
	int mid = (lo+hi) /2;
	sort(a,aux, lo, mid);
	sort(a,aux, mid+1,hi);
	merge(a, aux, lo, mid,hi);
	}
}

void merge(int a[], int aux[],int lo, int mid, int hi)
{
	//cout<<"Inside Merge"<<endl;
	int i = lo, j = mid+1;
	int len = arrlength;

	for(int k = 0 ; k < len ; k++)
		aux[k] = a[k]; //copy all the elements to the auxiliary array.

	for(int p = lo ; p <= hi ; p++)
	{
		if( i > mid ) a[p] = aux[j++];//No more elements in the first half, copy the right half to the element.
		else if ( j > hi ) a[p] = aux[i++];// No more elements in the sec half, copy the left half to the element.
		else if( aux[j] < aux[i] ) a[p] = aux[j++];
		else a[p] = aux[i++];	
	}
}		
