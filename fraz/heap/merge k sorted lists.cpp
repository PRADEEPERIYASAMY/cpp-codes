#include <iostream>
using namespace std;

ListNode* mergeKLists(vector<ListNode*>& lists) {
    auto cmp = [](ListNode*&a,ListNode*&b){
        return a->val >b->val;
    };
    priority_queue<ListNode*,vector<ListNode*>,decltype(cmp)> pq(cmp);
    for (auto &list : lists) if(list) pq.push(list);
    ListNode *head = nullptr,*pre = nullptr,*tmp = nullptr;
    while(!pq.empty()){
        tmp = pq.top();pq.pop();
        if(!pre) head = tmp;
        else pre->next = tmp;
        pre = tmp;
        if(tmp->next) pq.push(tmp->next);
    }
    return head;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/merge-k-sorted-lists/
	return 0;
}

