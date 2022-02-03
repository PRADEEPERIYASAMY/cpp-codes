#include <iostream>
using namespace std;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(-1),*cur = dummy;
    int carry = 0;
    while(l1 || l2){
        int num = 0;
        if(l1){
            num+=l1->val;
            l1 = l1->next;
        }
        if(l2){
            num+=l2->val;
            l2 = l2->next;
        }
        num+=carry;
        cur->next = new ListNode(num%10);
        cur = cur->next;
        carry = num/10;
    }
    if(carry) cur->next = new ListNode(carry);
    ListNode *res = dummy->next;
    delete dummy;
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/add-two-numbers/
	return 0;
}

