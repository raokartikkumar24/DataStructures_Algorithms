// stack.cpp : Defines the entry point for the console application.
//



#include<iostream>
using namespace std;

class stack {

private:
int *mainArray;
int *minArray;
int index;
int minIndex;

public:

stack(int size)
{
	index = -1;
	minIndex = -1;
	mainArray = new int[size];
	minArray = new int[size];
	
}

void push(int element)
{
	if( index == -1 ) 
	{
		mainArray[++index] = element;
		minArray[++minIndex] = element;
		
	}
	
	else if( element < minArray[minIndex] )
	{
		minArray[++minIndex] = element;
	}
	
	else {
		mainArray[++index] = element;
	}

}

int pop()
{
	return (minArray[minIndex--]);
}

};

int main()
{
	stack s1(10);
	
	s1.push(10);
	s1.push(100);
	s1.push(23);
	s1.push(32);
	s1.push(110);
	s1.push(140);
	s1.push(150);
	s1.push(1);
	s1.push(189);
	s1.push(288);
	
	cout<<s1.pop();
	
	return 0;
}


