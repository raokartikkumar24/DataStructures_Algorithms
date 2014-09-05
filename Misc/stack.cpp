#include<iostream>
#include<vector>
using namespace std;
class CStackDynamicVector
{

public:

CStackDynamicVector():index(-1)
{
	//vStack = new vector<int>();
}

void push(int item)
{
	index++;
	//cout<<"before Pushing into stack"<<endl;
	//vStack[index] = item;
	vStack.push_back(item);
	//cout<<"After Pushing into stack"<<endl;
}


int pop()
{
	return vStack[index--];
}
	
private:
vector<int> vStack;
int index;	
	
};

//#define MAX 10
class CStackArray
{
	

	public:
	CStackArray(int size)
	{
		index = -1;
		arr = new int[size];
		capacity = size;
	}
	void push(int item)
	{
		//cout<<"pushing element "<<item<<endl;
		if(index >= capacity) cout<<"Stack overflow. Cannot insert more items into the stack"<<endl;
		else
		{
			index++;			
			arr[index] = item;
			//cout<<"Pushed the item :"<<item;
		}
	}

	int pop()
	{
		if( index <=-1 ) cout<<"Stack underflow. Stack is not initialized!!"<<endl;
		else
		{
			return arr[index];
			index--;
		}
		
	}
	private:
	int *arr;
	int index;
	int capacity;

};
int main()
{
	cout<<"Dynamic vector"<<endl;
	CStackDynamicVector stack;
	stack.push(10);
	stack.push(20);
	stack.push(30);
	stack.push(40);
	stack.push(50);

	cout<<stack.pop()<<endl;


	cout<<"Static stack"<<endl;

	CStackArray staticStack(10);
	staticStack.push(100);
	staticStack.push(200);
	staticStack.push(300);
	staticStack.push(400);
	staticStack.push(500);
	staticStack.push(600);

	cout<<staticStack.pop()<<endl;

	
	return 0;
}
