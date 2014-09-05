#include<iostream>
using namespace std;


//1. sorting and then scan the list once --> n
//2. Build a BST, since the numbers in the array is not sorted,
//   we can insert into the tree. if equal ele is found, the increment the counter.
//3. Keep another array = to size of i/p array. use counting algo

void Ntraverse(int a[])
{
	int count = 0;
	int j;
	int i = 0;
	int element = -1;
	for( ; i < 100 ; )
	{
		j = i;
		while( a[j] == a[++i] ) 
		 {
			cout<<" equal "<<endl;
			count++;
			//li++;
		 }
		 
		if( count > 0 )
				element = a[j];
		//else
    		//i++;

		 count = 0;
		 j =i;
		
	}
		cout<<endl<<element<<" is the repeated word "<<endl;
}


int main()
{
	
	int *arr = new int[100];
	for(int i = 0 ; i < 100;i++)
			arr[i] = i;
	
	arr[2] = 9;	
	
	cout<<endl;
	
	Ntraverse( arr );
	cout<<endl;
	
}
