/***
 — Merge linked lists list1 and list2 such that
 — given a & b , remove the elements in the list1 from a to b and replace them with list2.
 — Example : list1 1 4 5 9 8
 List2 3 4 5
 A = 2 and b = 4
 Final list should be 1 3 4 5 9 8 i.e 4 and 5 of list1 has been replace by 3 4 5 of list2
 **/

#include<iostream>
using namespace std;

class node {
public:
    int val;
    node *next;
    
    node(int _val) : val(_val),next( NULL ) { }
    
    node *insert(node* t, int x ) {
        if ( t == NULL ) {
            t = new node( x );
            t->val = x;
            t->next = NULL;
            return t;
        }
        else {
            t = new node( x );
            t->val = x;
            t->next = this;
            return t;
        }
    }
    
    void printList(node *h){
        node *head = h;
        while(head){
            cout << head->val << " ";
            head = head->next;
        }
        
        cout << "\n";
    }
    
    
    /**
     Complexity is a + b + O(sizeof(list2))
     **/
    node * mergeLinkedList(node *list1, node *list2, int a, int b){
        if(a < 1) return NULL;
        
        //TODO : check for the length of list1 and if b is greater than that return NULL
        
        if(!list2) return list1;
        if(!list1) return list2;
        
        node *firstList = list1;
        
        node *head = list1;
        
        int i = 1;
        node *temp = firstList;
        while(i < a){
            temp = firstList;
            firstList = firstList->next;
            i++;
        }
        
        int j = a;
        node *node2 = firstList;
        while(j < b){
            node2 = node2->next;
            j++;
        }
        
        temp->next = list2;
        while(list2->next != NULL){
            list2 = list2->next;
        }
        
        list2->next = node2->next;
        
        return head;
    }
};


int main()
{
    node *list1 = NULL;
    
    list1 = list1->insert(list1,10);
    list1 = list1->insert(list1,20);
    list1 = list1->insert(list1,30);
    list1 = list1->insert(list1,40);
    list1 = list1->insert(list1,50);
    list1 = list1->insert(list1,60);
    
    cout << "List 1 \n";
    list1->printList(list1);
    
    node *list2 = NULL;
    
    list2 = list2->insert(list2,100);
    list2 = list2->insert(list2,200);
    list2 = list2->insert(list2,300);
    list2 = list2->insert(list2,88);
    list2 = list2->insert(list2,11);
    list2 = list2->insert(list2,56);
    list2 = list2->insert(list2,2012);
    
    cout << "List 2 \n";
    list2->printList(list2);
    
    int a = 2 , b = 5;
    
    node *result = list1->mergeLinkedList(list1, list2, a, b);
    
    cout << "Merged : \n";
    result->printList(result);
    
    
    cout<<endl;
    
}


