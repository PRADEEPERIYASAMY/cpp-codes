#include <iostream>
using namespace std;

// Two Stacks + Iteration
// ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//     stack<int> s1,s2;
//     while(l1){
//         s1.push(l1->val);
//         l1 = l1->next;
//     }
//     while(l2){
//         s2.push(l2->val);
//         l2 = l2->next;
//     }
//     int sum = 0;
//     ListNode *res = new ListNode(0);
//     while(!s1.empty() || !s2.empty()){
//         if(!s1.empty()){
//             sum +=s1.top();s1.pop();
//         }
//         if(!s2.empty()){
//             sum+=s2.top();s2.pop();
//         }
//         res->val = sum%10;
//         ListNode *head = new ListNode(sum/10);
//         head->next = res;
//         res = head;
//         sum/=10;
//     }
//     if(res->val == 0){
//         ListNode* t = res;
//         res = res->next;
//         delete t;
//     }
//     return res;
// }

// Recursion
int getLength(ListNode *head){
    if(!head) return 0;
    int res = 0;
    while(head){
        res++;
        head = head->next;
    }
    return res;
}

ListNode* helper(ListNode* l1, ListNode* l2, int d) {
    if(!l1) return nullptr;
    ListNode *res = d == 0? new ListNode(l1->val+l2->val):new ListNode(l1->val);
    ListNode *post = d == 0? helper(l1->next,l2->next,0):helper(l1->next,l2,d-1);
    if(post && post->val>9){
        post->val %=10;
        res->val++;
    }
    res->next = post;
    return res;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int m = getLength(l1),n = getLength(l2);
    ListNode *head = new ListNode(1);
    head->next = (m>n)? helper(l1,l2,m-n):helper(l2,l1,n-m);
    if(head->next->val>9) head->next->val %=10;
    else {
        ListNode *t = head;
        head = head->next;
        delete t;
    }
    return head;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/add-two-numbers-ii/
	return 0;
}

