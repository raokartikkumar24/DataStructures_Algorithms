#include<iostream>
using namespace std;

class node {
public:
int val;
node *next; 

node(int _val) : val(_val),next( NULL ) { }

node *insert(node* t, int x )
{
	if ( t == NULL )
	{
		t = new node( x );
		t->val = x;
		t->next = NULL;
		return t;

	}
	else
	{
		t = new node( x );
		t->val = x;
		t->next = this;
		return t;

	}

}


void *print()
{
	cout<<"Enter print "<<endl;
	node *t = this;
	while( t->next != NULL )
	{
		cout<<t->val<<" ";
		t = t->next;
	}
	cout<<t->val;

	cout<<endl;
}


node *reverese(node *t)
{
	if( t )
	{
		reverese(t->next);
		cout<<t->val<<" ";

	}


}

node* ReverseList(node *head)
{
  // Complete this method
    node *current,*previous,*nextNode;
    current = head;
    previous = NULL;
    while( current )
    {
           nextNode = current->next;
           current->next = previous;
           previous = current;
           current = nextNode;
    }
    head = previous;
    return head;
}

};


int main()
{
	node *newNode = NULL;
	
	newNode = newNode->insert(newNode,10);
	newNode = newNode->insert(newNode,20);
	newNode = newNode->insert(newNode,30);
	newNode = newNode->insert(newNode,40);
	newNode = newNode->insert(newNode,50);

	cout<<"Normal"<<endl;
	newNode->print();
	cout<<endl;
	cout<<"Reverse"<<endl;
	newNode->reverese(newNode);

	cout<<endl;

}
