#include <iostream>
using namespace std;

class Node {

public:
int data;
Node *next;
Node *prev;


Node(){
next = NULL;
prev = NULL;

}


void print(Node *head){

	while(head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
}


Node* SortedInsert(Node *head,int data)
{
    if(!head){
        head = new Node;
        head->data= data;
        head->next = NULL;
        head->prev = NULL;
        
        return head;
    }
    
    if(head->next == NULL){
        Node *newNode = new Node;
        newNode->data = data;
        if(data > head->data){
            newNode->next= NULL;
            newNode->prev = head;
            head->next = newNode;
             return head;
        }
        else {
             newNode->prev = NULL;
            newNode->next = head;
            head->prev = newNode;
            return newNode;
        }       
    }
    
    Node *temp = head;
    
    Node *prev;
    
    while( temp->next != NULL && (data > temp->data)){
        prev = temp;
        temp = temp->next;
    }
    
    Node *newnode = new Node;
    newnode->data = data;
    
    if(temp->next == NULL){
	if(data > temp->data) {
        temp->next = newnode;
        newnode->next = NULL;
        newnode->prev = temp;
	}
	else {
		 newnode->next = temp;
        newnode->prev = temp->prev;
        prev->next = newnode;
        temp->prev = newnode;	
	}
    }
    else {
        newnode->next = temp;
        newnode->prev = temp->prev;
        prev->next = newnode;
        temp->prev = newnode;
    }
    
    return head;
}
    
    Node* Reverse(Node* head)
    {
        Node *temp = NULL;
        Node *current = head;
        
        
        while (current !=  NULL)
        {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        if(temp != NULL )
            head = temp->prev;
        
        return head;
        
    }
    
};


int main() {

	Node *head = NULL;
	int N;
	cin >> N;
	while(N--){
		int d;
		cin >> d;
		head = head->SortedInsert(head,d);
	 }
	head->print(head);
    cout << endl;
    head->Reverse(head);
    cout << endl;
    head->print(head);

return 0;
}
