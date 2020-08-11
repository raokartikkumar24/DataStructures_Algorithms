#include <iostream>
using namespace std;

class node {
public:
int val;
node *next; 

node(int _val) : val(_val),next( NULL ) { }

node *insert(node* t, int x )
{
	t = new node( x );
	t->val = x;
	if ( t == NULL )
	{
		t->next = NULL;
	}
	else
	{
		t->next = this;
	
	}
	return t;

}


void *print()
{
	//cout<<" \nEnter print "<<endl;
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

 node* rotateRight(node* head, int k) {
        
        node *lastNode = head;
        int counter = 0;
        int len = 0;
        node *prevNode = head;
        while(lastNode != nullptr) {
        	prevNode = lastNode;
            lastNode = lastNode->next;
            len++;
        }

        while(k--) {
        	lastNode->next = head;
        	prevNode->next = nullptr;
        	head = lastNode;
        }

        return head;
    }

};


int main()
{
	node *newNode = NULL;
	
	newNode = newNode->insert(newNode,5);
	newNode = newNode->insert(newNode,4);
	newNode = newNode->insert(newNode,3);
	newNode = newNode->insert(newNode,2);
	newNode = newNode->insert(newNode,1);

	int k  = 2;

	cout<<"Normal"<<endl;
	newNode->print();
	cout<<endl;
	
	node *result = result->rotateRight(newNode, k);
	result->print();

	cout<<endl;

}
