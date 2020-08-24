#include <iostream>
#include <vector>
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
        if( n == NULL ) {
            n->next =  NULL;
            return n;
        }
        else {
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

     ListNode *reorderlist(ListNode *head) {

         vector<ListNode*> allList;
         ListNode *tempNode = head;
         while(tempNode) {
            allList.push_back(tempNode);
            tempNode = tempNode->next;
         }

         int listlen = allList.size();

         for(int i = 0 ; i < listlen / 2; i++) {

            allList[i]->next = allList[listlen - 1 - i];
            allList[listlen - 1 - i]->next = allList[i+1];

            if(i + 1 == listlen/2) {
                if(listlen%2 != 0) {
                    allList[i+1]->next = NULL;
                }
                else {
                    allList[listlen-1-i]->next = NULL;
                }
            }
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
    
     l1 = l1->insert(l1,8);
    l1 = l1->insert(l1,7);
    l1 = l1->insert(l1,6);
    l1 = l1->insert(l1,5);
    l1 = l1->insert(l1,4);
    l1 = l1->insert(l1,3);
    l1 = l1->insert(l1,2);
    l1 = l1->insert(l1,1);

    l1 = l1->reorderlist(l1);

    l1->display(l1);
   

    return 0;
}