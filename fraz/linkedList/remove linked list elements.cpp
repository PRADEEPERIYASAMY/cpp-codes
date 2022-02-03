#include <iostream>
using namespace std;

// Iteration
// ListNode* removeElements(ListNode* head, int val) { 
//     ListNode* dummy = new ListNode(-1),*pre = dummy;
//     dummy->next = head;
//     while(pre->next){
//         if(pre->next->val == val){
//             ListNode* t = pre->next;
//             pre->next = t->next;
//             delete t;
//         }else{
//             pre = pre->next;
//         }
//     }
//     ListNode *res = dummy->next;
//     delete dummy;
//     return res;
// }

// Recursion
ListNode* removeElements(ListNode* head, int val){
    if(!head) return nullptr;
    head->next = removeElements(head->next,val);
    return head->val == val?head->next:head;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/remove-linked-list-elements/
	return 0;
}

