#include <iostream>
using namespace std;

bool isPalindrome(ListNode* head) {
    if(!head || !head->next) return true;
    ListNode *slow = head,*fast = head;
    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *pre = head,*last = slow->next;
    while(last->next){
        ListNode *next = last->next;
        last->next = next->next;
        next->next = slow->next;
        slow->next = next;
    }
    while(slow->next){
        slow = slow->next;
        if(pre->val != slow->val) return false;
        pre  = pre->next;
    }
    return true;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/palindrome-linked-list/
	return 0;
}

