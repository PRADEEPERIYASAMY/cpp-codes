#include <iostream>
using namespace std;

// Top-Down Mergesort time: O(nlogn); space: O(logn)
// ListNode* merge(ListNode *l1, ListNode *l2) {
//     ListNode *dummy = new ListNode(INT_MIN),*pre = dummy;
//     while(l1&&l2){
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

// ListNode* sortList(ListNode* head) { 
//     if(!head || !head->next) return head;
//     ListNode *slow = head,*fast = head;
//     while(fast->next && fast->next->next) slow = slow->next,fast = fast->next->next;
//     fast = slow->next;
//     slow->next = nullptr;
//     ListNode *l1 = sortList(head),*l2 = sortList(fast);
//     return merge(l1,l2);
// }

// time: O(nlogn); space: O(1) // Bottom-Up
ListNode* split(ListNode* head,int n){
    for (int i = 1; head && i < n; i++)  head = head->next;
    if(!head) return nullptr;
    ListNode *second_head = head->next;
    head->next = nullptr;
    return second_head;
}

ListNode* merge(ListNode *l1,ListNode* l2,ListNode *head){
    ListNode *cur = head;
    while(l1 && l2){
        if(l1->val < l2->val) cur->next = l1,l1 = l1->next;
        else cur->next = l2,l2 = l2->next;
        cur = cur->next;
    }
    if(l1) cur->next = l1;
    else if(l2) cur->next = l2;
    while(cur->next) cur = cur->next;
    return cur;
}

ListNode* sortList(ListNode* head) {
    if(!head || !head->next) return head;
    ListNode *cur = head;
    int len = 0;
    while(cur){
        len++;
        cur = cur->next;
    }
    ListNode *dummy = new ListNode(INT_MIN),*left = nullptr,*right = nullptr,*tail = nullptr;
    dummy->next = head;
    for (int i = 1; i < len; i*=2) {
        cur = dummy->next;
        tail = dummy;
        while(cur){
            left = cur;
            right = split(left,i);
            cur = split(right,i);
            tail = merge(left,right,tail);
        }
    }
    ListNode *res = dummy->next;
    delete dummy;
    return res;
}
    
int main() {
	// leetcode
	// https://leetcode.com/problems/sort-list/
	return 0;
}

