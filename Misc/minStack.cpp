#include<iostream>
using namespace std;


void push(int item);
int pop();
int GetMinimumElement();
void displayMainStack();
void displayMinStack();
class mainstack
{

public:
mainstack(int size)
{
	cout<<"Creating Main Stack"<<endl;
	index = -1;
	arr= new int[size];
	capacity = size;
}

void push(int item)
{
	cout<<"Main Stack. Pushing item : "<<item<<endl;
	index++;
	arr[index] = item;
	cout<<"Main Stack Index after pushing item "<<item<<" is "<<index<<endl;
}


int capacity;
int *arr;
int index;
};

class minstack {

public:
minstack(int size)
{
	cout<<"Creating Min Stack"<<endl;
	index = -1;
	arr= new int[size];
	capacity = size;
}


void push(int item)
{
	cout<<"Min Stack. Pushing item : "<<item<<endl;
	index++;
	arr[index] = item;
	cout<<"Min Stack Index after pushing item "<<item<<" is "<<index<<endl;
}

int capacity;
int *arr;
int index;

};

//create main and min empty stacks
mainstack s1(5);
minstack s2(5);


int GetMinimumElement()
{
	//s2.index--;

	int min = s2.arr[s2.index];
	s2.index--;
	cout<<"Getting the minumum element : "<<min<<endl;;	
	return min;
}

int pop()
{
	if( s1.index == -1 ) cout<<"Stack Underflow!!"<<endl;
	else
		return s1.arr[s1.index--];

}

void push(int item)
{
	

	if(s1.index == -1 && s2.index == -1)
	{
		//both the stacks are empty
		cout<<"Inserting into the empty stacks"<<endl;
		
		s1.push(item);s2.push(item);
		cout<<"Leaving after inserting into the empty stacks"<<endl;
	}		
	else if( item < s2.arr[s2.index] )
	{
		cout<<"Inserting the minimum element into both the stacks"<<endl;

		
		s1.push(item);
		s2.push(item);	
		cout<<"Leaving after Inserting the minimum element into both the stacks"<<endl;
	}

	else if ( s1.index > s1.capacity )
		cout<<"Main stack overflow"<<endl;
	else if ( s2.index > s2.capacity )
		cout<<"Minimum stack overflow"<<endl;
	else
	{
		cout<<"Inserting the  element into  the main stack"<<endl;
		
		s1.push(item);
		cout<<"leaving the push fucntion"<<endl;
	}	
}

void displayMainStack()
{
	cout<<"index of main stacks is : "<<s1.index<<endl;
	for(int i = 0 ; i < 5 ; i++ )
		cout<<s1.arr[i]<<"\t";
}


void displayMinStack()
{
	cout<<"index of the minimum stack is :"<<s2.index<<endl;
	for(int i = 0 ; i <= s2.index ; i++)
		cout<<s2.arr[i]<<"\t";
}


int main()
{
	push(10);
	push(4);
	push(1);
	push(20);
	push(40);

	displayMainStack();
	cout<<endl;
	displayMinStack();

	cout<<pop()<<endl;
	cout<<GetMinimumElement();


	return 0;
}
