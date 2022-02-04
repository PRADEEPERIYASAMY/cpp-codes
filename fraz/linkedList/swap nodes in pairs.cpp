#include <iostream>
using namespace std;

// Iteration
// ListNode* swapPairs(ListNode* head) {
//     ListNode *dummy = new ListNode(INT_MIN);
//     dummy->next = head;
//     ListNode *pre = dummy,*cur = head,*next = nullptr;
//     while(cur && cur->next){
//         next = cur->next;
//         cur->next = next->next;
//         next->next = cur;
//         pre->next = next;
//         pre = cur;
//         cur = cur->next;
//     }
//     ListNode *res = dummy->next;
//     delete dummy;
//     return res;
// }

// Recursion
ListNode* swapPairs(ListNode* head) {
    if(!head || !head->next) return head;
    ListNode *n = head->next;
    head->next = swapPairs(n->next);
    n->next = head;
    return n;
} 
    
int main() {
	// leetcode
	// https://leetcode.com/problems/swap-nodes-in-pairs/
	return 0;
}

