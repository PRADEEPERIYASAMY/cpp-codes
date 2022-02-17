#include <iostream>
using namespace std;

ListNode *reverseList(ListNode *pre,ListNode* next){
    ListNode *last = pre->next,*cur = last->next;
    while(cur != next){
        last->next = cur->next;
        cur->next = pre->next;
        pre->next = cur;
        cur = last->next;
    }
    return last;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    if(!head || k == 1) return head;
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    ListNode *cur = head,*pre = dummy;
    int i = 0;
    while(cur){
        i++;
        if(i%k == 0){
            pre = reverseList(pre,cur->next);
            cur = pre->next;
        }else cur = cur->next;
    }
    ListNode *res = dummy->next;
    delete dummy;
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/reverse-nodes-in-k-group/
	return 0;
}

