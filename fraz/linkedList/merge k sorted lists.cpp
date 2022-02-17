#include <iostream>
using namespace std;

// ListNode* mergeKLists(vector<ListNode*>& lists) {
//     auto cmp = [](ListNode *&a,ListNode *&b){return a->val > b->val;};
//     priority_queue<ListNode*,vector<ListNode*>,decltype(cmp)> pq(cmp);
//     ListNode *head = nullptr,*pre = nullptr,*temp = nullptr;
//     for (auto &list : lists) if(list) pq.push(list);
//     while(!pq.empty()){
//         temp = pq.top();pq.pop();
//         if(!pre) head = temp;
//         else pre->next = temp;
//         pre = temp;
//         if(temp->next) pq.push(temp->next);
//     }
//     return head;
// }

ListNode* mergeTwoLists(ListNode* l1,ListNode* l2){
    ListNode *dummy = new ListNode(-1),*pre = dummy;
    while(l1 && l2){
        if(l1->val <l2->val){
            pre->next = l1;
            l1 = l1->next;
        }else{
            pre->next = l2;
            l2 = l2->next;
        }
        pre = pre->next;
    }
    if(l1) pre->next = l1;
    else if(l2) pre->next = l2;
    ListNode* res = dummy->next;
    delete dummy;
    return res;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.empty()) return nullptr;
    int n = lists.size();
    while(n>1){
        int k = (n+1)/2;
        for (int i = 0; i < n/2; i++) {
            lists[i] = mergeTwoLists(lists[i],lists[k+i]);
        }
        n = k;
    }
    return lists[0];
}

int main() {
	// leetcode
	// https://leetcode.com/problems/merge-k-sorted-lists/
	return 0;
}

