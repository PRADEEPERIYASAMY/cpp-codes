#include <iostream>
using namespace std;

// Iteration with 3 passes
// void reorderList(ListNode* head) {
//     if(!head || !head->next || !head->next->next) return;
//     ListNode *fast,*slow;
//     fast = slow = head;
//     while(fast->next && fast->next->next){
//         fast = fast->next->next;
//         slow = slow->next;
//     }
//     ListNode *mid = slow->next;
//     slow->next = nullptr;
//     ListNode *cur = mid,*pre = nullptr,*next = nullptr;
//     while(cur){
//         next = cur->next;
//         cur->next = pre;
//         pre = cur;
//         cur = next;
//     }
//     ListNode *p1 = head,*p2 = pre;
//     while(p1 && p2){
//         next = p1->next;
//         p1->next = p2;
//         p2 = p2->next;
//         p1->next->next = next;
//         p1 = next;
//     }
// }

// Stack
void reorderList(ListNode* head) {
    if(!head || !head->next || !head->next->next) return;
    stack<ListNode*> st;
    ListNode *cur = head;
    while(cur){
        st.push(cur);
        cur = cur->next;
    }
    int cnt = (st.size()-1)/2;
    cur = head;
    while(cnt--){
        ListNode *t = st.top();st.pop();
        ListNode* next = cur->next;
        cur->next = t;
        t->next = next;
        cur = next;
    }
    st.top()->next = nullptr;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/reorder-list/
	return 0;
}

