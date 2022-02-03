#include <iostream>
using namespace std;

// Iteration + Hash table
// Node* copyRandomList(Node* head) {
//     if(!head) return nullptr;
//     unordered_map<Node*,Node*> mp;
//     Node *cur = head;
//     while(cur){
//         mp[cur] = new Node(cur->val,nullptr,nullptr);
//         cur = cur->next;
//     }
//     cur = head;
//     while(cur){
//         mp[cur]->next = mp[cur->next];
//         mp[cur]->random = mp[cur->random];
//         cur = cur->next;
//     }
//     return mp[head];
// }

// Recursion + Hash table
// unordered_map<Node*, Node*> mp;
// Node* copyRandomList(Node* head) {
//     if(!head) return nullptr;
//     if(mp[head]) return mp[head];
//     Node* node = new Node(head->val,nullptr,nullptr);
//     mp[head] = node;
//     node->next = copyRandomList(head->next);
//     node->random = copyRandomList(head->random);
//     return node;
// }

// Constant space
Node* copyRandomList(Node* head) { 
    if(!head) return nullptr;
    Node *cur = head,*next = nullptr;
    while(cur) {
        next = cur->next;
        Node *node = new Node(cur->val,nullptr,nullptr);
        cur->next = node;
        node->next = next;
        cur = next;
    }
    cur = head;
    while(cur){
        if(cur->random) cur->next->random = cur->random->next;
        cur = cur->next->next;    
    }
    cur = head;
    Node *dummy = new Node(-1e7,nullptr,nullptr),*pre =dummy;
    while(cur){
        next = cur->next;
        pre->next = next;
        pre = pre->next;
        cur->next = next->next;
        cur = cur->next;
    }
    Node *res = dummy->next;
    delete dummy;
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/copy-list-with-random-pointer/
	return 0;
}

