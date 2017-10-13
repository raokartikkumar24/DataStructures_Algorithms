#include <iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
struct Node
{
    int data;
    Node *next;
};



void print(Node *head){
    
    if(head != NULL){
        print(head->next);
        cout << head->data << " ";
    }
}

bool checkForPalindrome(Node *mid, Node *first){
    static bool palin = true;
    if(mid != NULL){
        checkForPalindrome(mid->next, first);
        if(mid->data == first->data){
            palin = true;
        }
        else {
            palin = false;
        }
    }
    return palin;
}

bool isPalindrome(Node *head){
    
    if(head->next == NULL) return true;
    
    Node *slow = head;
    Node *fast = head;
    
    Node *first = head;
    
    while(fast || fast->next != NULL){
        if(fast->next->next == NULL) break;
        fast = fast->next->next;
        slow = slow->next;
        
    }
    slow = slow->next;
    
    bool isPalin = true;
    while(slow != NULL){
        if(slow->data == first->data){
            slow = slow->next;
            first = first->next;
        }
        else {
            isPalin = false;
            break;
        }
    }
    return isPalin;
}

Node* Insert(Node *head,int x)
{
    Node *temp = new Node();
    temp->data = x;
    temp->next = NULL;
    if(head == NULL)
    {
        return temp;
    }
    Node *temp1;
    for(temp1 = head;temp1->next!=NULL;temp1= temp1->next);
    temp1->next = temp;return head;
}
int main()
{
    int t;
    cin>>t;
    while(t-- >0)
    {
        Node *A = NULL;
        int m;cin>>m;
        while(m--){
            int x; cin>>x;
            A = Insert(A,x);
        }
        //        bool isP = isPalindrome(A);
        //        if(isP) cout << "Palindrom \n";
        //        else cout << "not a palindrome \n";
        
        print(A);
    }
}

