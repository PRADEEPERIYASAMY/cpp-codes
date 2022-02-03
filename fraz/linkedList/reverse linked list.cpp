#include <iostream>
using namespace std;

// ListNode* reverseList(ListNode* head) {
//     ListNode *pre = nullptr,*cur = head,*next = nullptr;
//     while(cur){
//         next = cur->next;
//         cur->next = pre;
//         pre = cur;
//         cur = next;
//     }
//     return pre;
// }

ListNode* reverseList(ListNode *head){
    if(!head || !head->next) return head;
    ListNode *node = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return node;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/reverse-linked-list/
	return 0;
}

