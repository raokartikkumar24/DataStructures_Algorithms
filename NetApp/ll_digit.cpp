//Convert the linked list to integer.
//Linked list has a single digit in its node. Traverse the list and multiply by 10 to the value
//Done using recursion

#include<iostream>
using namespace std;

class node {
		private:
		int val;
		node *next; 
		public:
		node(int _val) : val(_val),next( NULL ) { }

		node *insertnode(node* t, int x )
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

		void print()
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
		
		
		//Recursively call this method to calculate the total sum of the linked list
		int convertToDigit(node *t,int mul)
		{
			static int sum = 0;
				if( t != NULL )
				{
					convertToDigit(t->next,mul*10);
					sum += (t->val*mul);
					return sum;
					
				}
				
			return 0;
		
		}

};


int main()
{
	node *head = NULL;
	head = head->insertnode(head,8);
	head = head->insertnode(head,5);
	head = head->insertnode(head,6);
	
	//	head->print();
	
	int x = head->convertToDigit(head,1);
	cout<<x<<endl;
	
	return 0;

}