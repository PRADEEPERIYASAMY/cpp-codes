#include <iostream>
using namespace std;

// Iteration
// Node* flatten(Node* head) {
//     if(!head) return nullptr;
//     Node *p = head;
//     while(p){
//         if(!p->child){
//             p = p->next;
//             continue;
//         }
//         Node *tmp = p->child;
//         while(tmp->next) tmp = tmp->next;
//         tmp->next = p->next;
//         if(p->next) p->next->prev = tmp;
//         p->next = p->child;
//         p->child->prev = p;
//         p->child = nullptr;
//     }
//     return head;
// }

// Iteration
// Node* flatten(Node* head) {
//     Node *cur = head;
//     while(cur){
//         if(cur->child){
//             Node *next = cur->next,*last = cur->child;
//             while(last->next) last = last->next;
//             cur->next = cur->child;
//             cur->next->prev = cur;
//             cur->child = nullptr;
//             last->next = next;
//             if(next) next->prev = last;
//         }
//         cur = cur->next;
//     }
//     return head;
// }

// Recursion
Node* flatten(Node* head) {
    Node *cur = head;
    while(cur){
        if(cur->child){
            Node *next = cur->next;
            cur->child = flatten(cur->child);
            Node *last = cur->child;
            while(last->next) last = last->next;
            cur->next = cur->child;
            cur->next->prev = cur;
            cur->child = nullptr;
            last->next = next;
            if(next) next->prev = last;
        }
        cur =cur->next;
    }
    return head;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
	return 0;
}

