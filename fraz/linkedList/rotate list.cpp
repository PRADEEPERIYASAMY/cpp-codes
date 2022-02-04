#include <iostream>
using namespace std;

// Two pointers
// ListNode* rotateRight(ListNode* head, int k) {
//     if(!head) return nullptr;
//     int n = 0;
//     ListNode *cur = head;
//     while(cur){
//         n++;
//         cur = cur->next;
//     }
//     k%=n;
//     ListNode *slow = head,*fast = head;
//     for (int i = 0; i < k; i++) fast = fast->next;
//     while(fast->next) fast = fast->next,slow = slow->next;
//     fast->next = head;
//     fast = slow->next;
//     slow->next = nullptr;
//     return fast;
// }

// Connect the tail to head for rotation
ListNode* rotateRight(ListNode* head, int k) {
    if(!head) return nullptr;
    int n = 1;
    ListNode *cur = head;
    while(cur->next){
        n++;
        cur = cur->next;
    }
    cur->next = head;
    int m = n-k%n;
    for (int i = 0; i < m; i++) cur = cur->next;
    ListNode *headNode = cur->next;
    cur->next = nullptr;
    return headNode;
}
    
int main() {
	// leetcode
	// https://leetcode.com/problems/swap-nodes-in-pairs/
	return 0;
}

