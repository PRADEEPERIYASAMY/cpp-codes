using namespace std;
#include <bits/stdc++.h>

void deleteNode(ListNode* node) {
    ListNode *n = node->next;
    node->val = n->val;
    node->next = n->next;
    delete n;
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/delete-node-in-a-linked-list/
    return 0;
}

