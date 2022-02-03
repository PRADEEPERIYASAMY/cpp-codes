#include <iostream>
using namespace std;

bool hasCycle(ListNode *head) {
    if(!head || !head->next) return false;
    ListNode *slow,*fast;
    slow = fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true; 
    }
    return false;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/linked-list-cycle/
	return 0;
}

