#include<iostream>
using namespace std;

class node {
public:
int val;
node *next; 

node(int _val) : val(_val),next( NULL ) { }

node() : val(0) , next(NULL) {}

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

node *add2Numbers(node *l1, node* l2)
{
	node *newNode = new node;
	node *current = newNode;
	int carry = 0;
	while(l1 != NULL || l2 != NULL) {
		int l1_val = l1 ? l1->val : 0;
		int l2_val = l2 ? l2->val : 0;
		int sum = l1_val + l2_val + carry;
		carry = sum/10;
		current->next = new node(sum%10);
		current = current->next;
		if(l1) l1 = l1->next;
		if(l2) l2 = l2->next;
	}
	if(carry > 0) {
		current->next = new node(carry);
	}

	return newNode->next;
 }


void *print()
{
	node *t = this;
	while( t->next != NULL )
	{
		cout<<t->val<<" ";
		t = t->next;
	}
	cout<<t->val;

	cout<<endl;
}


};


int main()
{
	node *l1 = NULL;
	
	l1 = l1->insert(l1,1);
	l1 = l1->insert(l1,2);
	l1 = l1->insert(l1,3);

	node *l2 = NULL;
	l2 = l2->insert(l2,4);
	l2 = l2->insert(l2,5);
	l2 = l2->insert(l2,5);

	node *dummy = new node;

	node *sum = dummy->add2Numbers(l1,l2);

	sum->print();
	

	cout<<endl;

}
