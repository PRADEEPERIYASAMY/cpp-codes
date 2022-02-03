#include <iostream>
using namespace std;

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* cur = head;
    while(cur && cur->next){
        if(cur->val == cur->next->val){
            ListNode *temp = cur->next;
            cur->next = cur->next->next;
            delete temp;
        }else{
            cur = cur->next;
        }
    }
    return head;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/remove-duplicates-from-sorted-list/
	return 0;
}

