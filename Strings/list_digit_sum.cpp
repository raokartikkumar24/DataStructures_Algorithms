#include<iostream>

using namespace std;

class node {

public:

node(int v) : value( v ), next( NULL ) { }

node *insert(node* n,int v)
{
	n = new node(v);
	if( n == NULL )
		n->next = NULL;
	
	else
	 n->next = this;
	 
	return n;
		
	 
}

void dis(node *temp)
{
while( temp )
{
	cout<<temp->value<<" ";
	temp = temp->next;
}

}




void display() {

node *temp = this;
while( temp )
{
	cout<<temp->value<<" ";
	temp = temp->next;
}

}

node *reverse(node *n)
{
	node *nextNode = NULL, *currentNode = NULL;
	while(n)
	{
		nextNode  = n->next;
		n->next = currentNode;
		currentNode = n;
		n = nextNode;
		
	}
	
	return currentNode;
}

public:
int value;
node *next;

};

void add(node *n1, node *n2)
{
	if( n1 == NULL || n2 == NULL ) return;
	
	n1= n1->reverse(n1);
	n2= n2->reverse(n2);
	
	node *sum = NULL;
	int c = 0 ;
	int cc;
	while( n1 && n2)
	{
		int carry = (n1->value+n2->value)/10;
		if( c == 0  && carry > 0) 
		{	
			cc = carry;
		}
		if( c != 0 && carry > 0 )
			sum = sum->insert(sum,(((n1->value+n2->value)%10)) + cc);
		else
			sum = sum->insert(sum,(((n1->value+n2->value)%10)));
		n1 = n1->next;
		n2 = n2->next;
		c++;
		
	}
	
	if( n1 )
	{
		while(n1)
		{
			sum = sum->insert(sum,n1->value);
			n1 = n1->next;
		}
	}
	
	if( n2 )
	{
		while(n2)
		{
			sum = sum->insert(sum,n2->value);
			n2 = n2->next;
		}
	}
	//sum = sum->reverse(sum);
	if( sum ) sum->display();
	//need to use reverse
	
	
}

int main()
{
	
	node *num1 = NULL;
	
	num1 = num1->insert(num1,5);
	num1 = num1->insert(num1,0);
	num1 = num1->insert(num1,4);
	//num1 = num1->insert(num1,2);
	cout<<"First number "<<endl;
	num1->display();
	node *num2 = NULL;
	
	num2 = num2->insert(num2,5);
	num2 = num2->insert(num2,1);
	num2 = num2->insert(num2,4);
	cout<<endl<<"Second number "<<endl;
	num2->display();
	cout<<endl<<"Addition"<<endl;
	add(num1,num2);
	
	return 0;
}