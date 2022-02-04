#include <iostream>
using namespace std;

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(!head) return nullptr;
    ListNode *dummy = new ListNode(INT_MIN);
    dummy->next = head;
    ListNode *fast = dummy,*slow = dummy;
    for (int i = 1; i <=n; i++) fast = fast->next;
    while(fast->next != nullptr) fast = fast->next,slow = slow->next;
    ListNode *t = slow->next;
    slow->next = slow->next->next;
    delete t;
    ListNode* res = dummy->next;
    delete dummy;
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
	return 0;
}

