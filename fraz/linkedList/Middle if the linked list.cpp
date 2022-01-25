using namespace std;
#include <bits/stdc++.h>

ListNode* middleNode(ListNode* head) {
    if(head == nullptr) return head;
    ListNode *slow,*fast;
    slow = fast = head;
    while(fast != nullptr && fast->next != nullptr) slow = slow->next,fast = fast->next->next;
    return slow;
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/middle-of-the-linked-list/
    return 0;
}

