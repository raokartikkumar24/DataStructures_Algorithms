// quickSort.cpp : Defines the entry point for the console application.
//

#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;

void sort(int a[],int l,int r);
int partition(int a[], int length, int r);
void sort(int a[], int length);
void swap(int a[], int i , int j);
int arrlength = 0;
//int inputElements();

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
    arrlength = c-1;
    sort(ele,arrlength);
    cout<<"The sorted elements are stored in sortedList_quick"<<endl;
    ofstream sortedNums("sortedList_quick.txt");

     for(int k = 0 ; k < arrlength ;k++ )
	sortedNums<<ele[k]<<"\n";

        sortedNums.close();
    /*for(int i = 0 ; i < arrlength ;i++)
        cout<<ele[i]<<" ";*/

    cout<<endl;
    return 0;
}


void sort(int a[], int length)
{
	//Need to shuffle the elements here so that time is improved
	//Ramdomness makes it more effecient as the pivot element that we choose will be random
	//shuffle(a);
	sort(a, 0, length-1);
}

void sort(int a[], int l, int r)
{
	if( r > l )
	{
		int pivot = partition(a, l, r);
		sort(a,l,pivot-1);
		sort(a,pivot+1,r);
	}
}

int partition(int a[], int l , int r)
{
	int i = l-1;
	int j = r;

	while( true )
	{
		while (a[++i]<a[r]) if( i==r) break; //check for elements less than pivot if not found then break and swap that element with the pivot element
		while (a[r]<a[--j]) if(j==l) break; //check for elements greateer than pivot if not found then break and swap that element with the pivot element

		if(i >= j ) break; //pointers overlap so break from here

		swap(a,i,j);

	}

	swap(a,i,r);//swap the pivot element
	return i;
}

void swap(int a[], int i, int j)
{
	int temp = a[i];
	a[i]= a[j];
	a[j] = temp;
}
