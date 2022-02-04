#include <iostream>
using namespace std;

ListNode* oddEvenList(ListNode* head) {
    if(!head) return nullptr;
    ListNode *odd  = head,*even = head->next,*evenHead = even;
    while(even && even->next){
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/odd-even-linked-list/
	return 0;
}

