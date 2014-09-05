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

node *removeDuplicates()
{
	node *temp = this;
	node* ptr1 = this;
	node *newnode = ptr1;
	while( ptr2 )
		{
			while( ptr2 && ptr1 &&(ptr1->value != ptr2->value))
			{
				//cout<<"Inside while loop"<<endl;
				temp = ptr2;
				ptr2 = ptr2->next;
			
			}
		
			if( ptr2 == NULL ) break;
			//found the node in ptr2
			if( ptr2->next == NULL ) temp->next = NULL; //the dup node is the last node
			else 	temp->next = ptr2->next;
			ptr2 = temp;
			
		}
		ptr1 = ptr1->next;
	//return ptr1;
	return newnode;
}


void display() {

node *temp = this;
while( temp )
{
	cout<<temp->value<<" ";
	temp = temp->next;
}

}

private:
int value;
node *next;
};


int main()
{
	node * head = NULL;
	head = head->insert(head,10);
	head = head->insert(head,50);
	head = head->insert(head,30);
	head = head->insert(head,50);
	head = head->insert(head,40);
	head = head->insert(head,50);
	
	head = head->removeDuplicates();
	
	head->display();
	
	return 0;
}