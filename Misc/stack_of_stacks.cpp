#include<iostream>
#include<vector>
#define MAX 10
using namespace std;

class stackofstacks
{
public:
stackofstacks()
{
	index = 0;
	vecIndex = 0;
	
}


void push(int element)
{
	if( index != MAX )
	{
		cout<<"index is : "<<index<<endl;
		sstack.push_back( element );
		index++;
	}
	
	else 
	{
		stack[vecIndex++].push_back( sstack );
		index  = 0;
	}	
}

private:
vector<vector<int> > stack[MAX];
vector<int> sstack;
int index;
int vecIndex;
};

int main()
{
	stackofstacks s1;
	for(int i = 1 ; i < 11; i++)
	{
		s1.push(i*19);
	}
	
	
	return 0;
}