#include<iostream>
#include<fstream>
using namespace std;


//  Definition for singly-linked list.
  /*struct ListNode {
      int value;
      ListNode *next;
      ListNode() : value(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : value(x), next(next) {}
  };
 */
class ListNode {
public:

     ListNode() : value(0), next(nullptr) {}
      ListNode(int x) : value(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : value(x), next(next) {}

    ListNode* insert(ListNode* n, int val )
    {
        n = new ListNode(val);
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

    void display(ListNode *t)
    {

        while( t->next != NULL )
        {
            cout<<t->value<<" ";
            t = t->next;
        }

        cout<<t->value<<endl;
        
    }

    ListNode* swapPairs(ListNode* head) {
        if(!head) return nullptr;
        
        if(head->next == nullptr) return head;
        
        ListNode *current = head;
        ListNode *t = head;
       // ListNode *t2 = nullptr;
        cout << "Cur" << "\t" << "t" << "\t" << "t2" << "\n";
        while(current) {
            cout << current->value << "\t";
            t = current->next;
            cout << t->value << "\t";
            ListNode *t2 = t->next;
            cout << t2->value << "\t";
            t->next = current;
            current->next = t2;
            current = t2;
            cout << current->value << "\t";
            cout << "\n";
           
        }
        
        return head;
    }

private:
    int value;
    ListNode *next;
};

int main()
{


    ListNode *l1 = NULL;
    
    l1 = l1->insert(l1,4);
    l1 = l1->insert(l1,3);
    l1 = l1->insert(l1,2);
    l1 = l1->insert(l1,1);


    l1->display(l1);

    ListNode *result = l1->swapPairs(l1);

    result->display(result);

    return 0;
}