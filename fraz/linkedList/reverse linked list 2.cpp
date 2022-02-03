#include <iostream>
using namespace std;

ListNode* reverseBetween(ListNode* head, int m, int n) {
    if(!head) return nullptr;
    ListNode *dummy = new ListNode(-1),*pre = dummy;
    pre->next = head;
    for (int i = 1; i < m; i++) pre = pre->next;
    ListNode *cur = pre->next,*next = cur->next;
    for (int i = m; i < n; i++) {
        cur->next = next->next;
        next->next = pre->next;
        pre->next = next;
        next = cur->next;
    }
    ListNode *res = dummy->next;
    delete dummy;
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/reverse-linked-list-ii/
	return 0;
}

