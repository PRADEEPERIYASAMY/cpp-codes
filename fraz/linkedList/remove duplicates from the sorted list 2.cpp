#include <iostream>
using namespace std;

// Iteration
// ListNode* deleteDuplicates(ListNode* head) {
//     if(!head || !head->next) return head;
//     ListNode *dummy = new ListNode(INT_MIN);
//     dummy->next = head;
//     ListNode *pre = dummy,*cur = head;
//     while(cur){
//         if(cur->next && cur->val == cur->next->val){
//             int curVal = cur->val;
//             while(cur && cur->val == curVal){
//                 ListNode *t = cur;
//                 cur = cur->next;
//                 delete t;
//             }
//             pre->next = cur;
//         }else {
//             pre = cur;
//             cur = cur->next;
//         }
//     }
//     ListNode *res = dummy->next;
//     delete dummy;
//     return res;
// }

// Recursion
ListNode* deleteDuplicates(ListNode* head) {
    if(!head || !head->next) return head;
    int curVal = head->val;
    ListNode *p = head->next;
    if(p->val == curVal){
        while(p && p->val == curVal){
            ListNode *t = p;
            p = p->next;
            delete t;
        }
        return deleteDuplicates(p);
    }else{
        head->next = deleteDuplicates(p);
        return head;
    }
}

int main() {
	// leetcode
	// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
	return 0;
}

