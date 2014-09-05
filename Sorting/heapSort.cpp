#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
typedef long long LL;
using namespace std;
class heapSort
{
	private:
	LL *ele;
	LL index;
	LL Num;
	public:
	heapSort(LL N)
	{	
		Num = N;
		ele = new LL[N];
		index= 0;
	}

	void swap(LL i , LL j )
	{
		LL temp = ele[i] ; 
		ele[i] = ele[j] ;
		ele[j] = temp;
	}

	//When we find that the position of the element is wrong,
	//we swim to the correct position.
	//we know that an element's parent is at k/2 if we start the array from 1
	void swim(LL k)
	{
	  //an element's parent is present in k/2 when we start the index at 1
	  while( k > 1 && ele[k/2] < ele[k] )
		{
			swap(k,k/2);//swap when we find the condition satisfied. We swap the parent with the child
			k = k/2;//increment over k/2 as the value is the location is that of the parent.
		}
	}

	void insert(LL value)
	{
		ele[++index] = value;//always insert at the last and then swim the element to the correct position
		swim(index);
	}

	void display()
	{
		for(LL i = 1 ; i < Num; i++)
			cout<<ele[i]<<" ";
		cout<<endl;
	}
 
	//Once we have removed the max elements( root ) , we need to sink the new root element the correct position
	//The max ele was swapped with the last element in the array
	void sink(LL k)
	{
		//2k and 2k+1 are the position of the k's children
		while( 2*k <= index )//checking if we have reached the end.
		{
			LL j  = 2*k;
			//Determining if we need to take the left child or the right child
			if(j < index && ele[j] < ele[j+1])//checking 2k and 2k+1
				j++;
			if(ele[k]>ele[j])break;//reached the correct position already
			swap(k,j);//swap the ele at k and j since j is greater than k
			k = j;//now make j as the parent
			
		}
	}
	LL deleteMax()
	{
		LL j = ele[1];//the first element is the max
		swap(1,index--);//swap with the last element
		sink(1);//balance the heap again
		return j;
	}

	void sort()
	{
		for(LL i = 1 ; i < Num ; i++ )
		{
			  deleteMax();
		}
	}

	void writeInFile()
	{
		cout<<"Num = " <<Num<<endl;
		ofstream sortedNums("sortedList_heap.txt");

		for(LL k = 1 ; k < Num ;k++ )
			sortedNums<<ele[k]<<"\n";

        sortedNums.close();
		
	}


};
int main()
{
	LL c = 0;
	
	string csNumbers;
	ifstream mystream("sortedList.txt");
	while(!mystream.eof())
	{
		getline(mystream,csNumbers);
		//
		//cout<<x;
		c++;
	}

	mystream.close();

	mystream.open("sortedList.txt");
	cout<<"no of nos "<<c<<endl;
	heapSort hea(c);
	LL *element = new LL[c];
	LL i = 0;
	while(!mystream.eof())
	{
		getline(mystream,csNumbers);
		LL x = atoi(csNumbers.c_str());
		if( x == 0 ) break;
		hea.insert(x);
		
	}
	mystream.close();
	cout<<endl;
	//hea.display();
	
	cout<<endl;

	hea.sort();

	//hea.display();
	cout<<"The sorted elements are stored in sortedList_heap"<<endl;

	hea.writeInFile();

	cout<<endl;

	//cout<<"C = "<<c<<endl;

return 0;
	

}
