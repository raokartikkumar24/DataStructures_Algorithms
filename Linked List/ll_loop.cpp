#include<iostream>
#include<fstream>
using namespace std;

class node {

public:
node(int _val) : value(_val),next(NULL){}

node* insert(node* n, int val )
{
	n = new node(val);
	if( n == NULL )
	{
		n->next =  NULL;
		return n;
	}
	else
	{
		n->next = this;
		return n;
	}
	
}

void display(node *t)
{

	while( t->next != NULL )
	{
		cout<<t->value<<" ";
		t = t->next;
	}

	cout<<t->value<<endl;
	
}

node* createLoop(node *n)
{	
	node *slow,*fast;
	slow = n;
	fast = n->next->next;
	while( fast->next != NULL )
	{
		fast = fast->next->next;
		slow = slow->next;
	}

	fast->next = slow;
	return fast;

}

int NumberOfNodes(node *n)
{
	node *slow,*fast;
	slow = n;
	fast = n->next->next;
	int count = 0;
	while( fast->next != NULL )
	{
		//cout<<fast->value<<" ";
		count++;
		fast = fast->next->next;
		slow = slow->next;
		if( fast->next == NULL )
		{
			cout<<"Mid elements is : "<<slow->value<<endl;
			while( slow->next != NULL )
			{
				slow = slow->next;
				count++;
			}
		}
		
	}
	
	return count;
}

int loopLocation(node *n)
{
	node *slow,*fast;
	slow = n;
	fast = n->next->next;
	
	while( fast != slow )
	{
		fast = fast->next->next;
		slow = slow->next;
	}

	slow = n;
	
	while( fast != slow )
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	
		
		
	return fast->value;

}

bool has_cycle(node* head) {
    
    if(!head) return false;
    
    if(head->next == NULL) return false;
    
    Node *slow;
    Node *fast;
    slow = head;
    fast = head->next->next;
    while(fast != slow) {
        if(!fast) return false;
        if(fast->next == NULL || slow->next == NULL) return false;
        fast = fast->next->next;
        slow = slow->next;
        
    }
    return true;
}

private:
int value;
node *next;
};
int main()
{
	node* newNode = NULL;	
	int n;
	ifstream str("num.txt");
	while( !str.eof() )
	{
		str>>n;
		newNode = newNode->insert(newNode,n);

	}
	
	newNode = newNode->createLoop(newNode);
	//newNode->display(newNode);
	cout<<endl;
	cout<<"Loop starts at : "<<newNode->loopLocation(newNode)<<endl;
	
}


