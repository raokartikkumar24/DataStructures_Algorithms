#include <iostream>
using namespace std;

class node {
public:
    int val;
    node *next;
    
    node(int _val) : val(_val),next( NULL ) { }
    
    node *insert(node* t, int x ) {
        if ( t == NULL ) {
            t = new node( x );
            return t;
        } else {
            t = new node( x );
            node *temp = this;
            while(temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = t;
            return this;
        }
    }
    
    
    void print() {
        node *t = this;
        while( t->next != NULL ) {
            cout<<t->val<<" ";
            t = t->next;
        }
        cout<<t->val << "\n";
    }
    
    
    node* ReverseListkNodes(node *head,int k) {
        
        node *current,*previous,*nextNode;
        current = head;
        previous = NULL;
        int count = 0;
        while( current && count < k ) {
            nextNode = current->next;
            current->next = previous;
            previous = current;
            current = nextNode;
            count++;
        }
        
        if(head)
            head->next = current;
        
        count = 0;
        
        //skip the next k nodes
        while(current && count < k) {
            count++;
            current = current->next;
        }
        
        if(current)
            current->next = ReverseListkNodes(current->next, k);
        
        
        return previous;
    }
    
};


int main()
{
    node *newNode = NULL;
    
    int N;
    cin >> N;
    while(N--) {
        int data;
        cin >> data;
        newNode = newNode->insert(newNode,data);
    }

    int k;
    cin >> k;
    
    cout << "original list \n";
    newNode->print();
    
    node *result = newNode->ReverseListkNodes(newNode,k);
    
    cout << "After reversing k nodes \n";
    if(result)
        result->print();
  
    cout<<endl;
    
}


