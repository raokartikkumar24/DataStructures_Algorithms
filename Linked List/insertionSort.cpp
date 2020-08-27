#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(NULL) {}
	ListNode(int _val) : val(_val), next(NULL) { }
};


class Solution {
public:

	ListNode *insertNode(ListNode *head, int val) {

		ListNode *newNode = new ListNode(val);

		if (head == NULL) {
			head = new ListNode(val);
		}
		else {
			ListNode *temp = head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = newNode;
		}
		return head;
	}


	void display(ListNode *head) {
		while (head) {
			std::cout << head->val << "\t";
			head = head->next;
		}
		std::cout << "\n";
	}

	ListNode* insertionSortList(ListNode* head) {
		vector<ListNode*> nodes;
		ListNode *temp = head;
		while (temp) {
			nodes.push_back(temp);
			temp = temp->next;
		}

		int len = nodes.size();

		for (int i = 0; i < len-1; i++) {
			for (int j = i + 1; j > 0; j--) {
				if (nodes[j - 1]->val > nodes[j]->val) {
					swap(nodes[j - 1], nodes[j]);
				}
			}
		}
		ListNode *newList = head;
		//newList = newList->next;
		for (int i = 0; i < len; i++) {
			newList->val = nodes[i]->val;
			newList = newList->next;
		}
		//newList->next = NULL;
		return head;
	}
};

int main()
{
	Solution sol;
	ListNode *head = NULL;
	head = sol.insertNode(head, 4);
	head = sol.insertNode(head, 2);
	head = sol.insertNode(head, 1);
	head = sol.insertNode(head, 3);

	ListNode *sortedList = sol.insertionSortList(head);

	sol.display(sortedList);

	return 0;

}