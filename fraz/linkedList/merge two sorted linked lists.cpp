#include <iostream>
using namespace std;


// // Iteration
// ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//     ListNode* dummy = new ListNode(-1),*pre = dummy;
//     while(l1&& l2){
//         if(l1->val <l2->val){
//             pre->next = l1;
//             l1 = l1->next;
//         }else{
//             pre->next = l2;
//             l2 = l2->next;
//         }
//         pre = pre->next;
//     }
//     if(l1) pre->next = l1;
//     else if(l2) pre->next = l2;
//     ListNode *res = dummy->next;
//     delete dummy;
//     return res;
// }

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(!l1) return l2;
    if(!l2) return l1;
    if(l1->val <l2->val){
        l1->next = mergeTwoLists(l1->next,l2);
        return l1;
    }else{
        l2->next = mergeTwoLists(l1,l2->next);
        return l2;
    }
}

int main() {
	// leetcode
	// https://leetcode.com/problems/merge-two-sorted-lists/
	return 0;
}

