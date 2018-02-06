#include<iostream>
using namespace std;

class node {
public:
    int val;
    node *next;
    
    node(int _val) : val(_val),next( NULL ) { }
    node() : next(NULL) {}
    
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
    
    void PrintOddEvenNodes(node *head) {
        if(!head) return;
        
        node *oddPtr = head;
        node *evenPtr = head->next;
        
        while(oddPtr && oddPtr->next != NULL) {
            printf("%d ",oddPtr->val);
            oddPtr = oddPtr->next->next;
        }
        
        printf("\n");
        
        while(evenPtr && evenPtr->next != NULL) {
            printf("%d ",evenPtr->val);
            evenPtr = evenPtr->next->next;
        }
        printf("%d \n",evenPtr->val);
    }
    
    
    void SplitOddEven(node *head) {
        if(!head) return;
        
        node *oddPtr = head;
        node *evenPtr = head->next;
        
        node *oddList = new node(head->val);
        node *evenList = new node(head->next->val);
        
        node *oddTemp = oddList;
        node *evenTemp = evenList;
        
        while(oddPtr && (oddPtr->next != NULL)) {
            oddPtr = oddPtr->next->next;
            if(oddPtr) {
                oddList->next = new node(oddPtr->val);
                oddList = oddList->next;
            }
        }
        oddList->next = NULL;
        
        while(evenPtr && evenPtr->next != NULL) {
            evenPtr = evenPtr->next->next;
            if(evenPtr) {
                evenList->next = new node(evenPtr->val);
                evenList = evenList->next;
            }
        }
        
        evenList->next = NULL;
        printf("Odd nodes\n");
        print(oddTemp);
        printf("Even nodes\n");
        print(evenTemp);
        
    }
    
    
    void print(node *root) {
        node *head = root;
        while(head != NULL) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << "\n";
    }
    
};


int main()
{
    node *newNode = NULL;
    
    newNode = newNode->insert(newNode,60);
    newNode = newNode->insert(newNode,50);
    newNode = newNode->insert(newNode,40);
    newNode = newNode->insert(newNode,30);
    newNode = newNode->insert(newNode,20);
    newNode = newNode->insert(newNode,10);
    printf("Original\n");
    newNode->print(newNode);
    newNode->SplitOddEven(newNode);
    printf("Just printing \n");
    newNode->PrintOddEvenNodes(newNode);
    cout<<endl;
    
}

