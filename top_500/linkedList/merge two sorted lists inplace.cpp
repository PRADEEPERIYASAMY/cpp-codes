#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

struct Node *newNode(int data){
    struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void push(struct Node** head_ref, int new_data){
    struct Node* new_node = newNode(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct Node *node){
    while(node != NULL){
        cout<<node->data;
        if(node->next)
            cout<<"->";
        node = node->next;
    }
    cout<<"\n";
}

// recursion
// Node *merge(Node *h1,Node *h2){
//     if(!h1) return h2;
//     if(!h2) return h1;
//     if(h1->data <h2->data){
//         h1->next = merge(h1->next,h2);
//         return h1;
//     }else{
//         h2->next = merge(h1,h2->next);
//         return h2;
//     }
// } 

// using iterative

Node *mergeUtil(Node *h1,Node *h2){
    if(!h1->next){
        h1->next = h2;
        return h1;
    }
    Node *curr1 = h1,*next1 = curr1->next;
    Node *curr2 = h2,*next2 = curr2->next;
    while(next1 && curr2){
        if(curr2->data >= curr1->data && curr2->data <= next1->data){
            next2 = curr2->next;
            curr1->next = curr2;
            curr2->next = next1;
            curr1 = curr2;
            curr2 = next2;
        }else{
            if(next1->next){
                next1 = next1->next;
                curr1 = curr1->next;
            }else{
                next1->next = curr2;
                return h1;
            }
        }
    }
    return h1;
}

Node *merge(Node *h1,Node *h2){
    if(!h1) return h2;
    if(!h2) return h1;
    if(h1->data<h2->data) return mergeUtil(h1,h2);
    else return mergeUtil(h2,h1);
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/merge-two-sorted-lists-place/
	Node* head1 = newNode(1);
    head1->next = newNode(3);
    head1->next->next = newNode(5);
    Node* head2 = newNode(0);
    head2->next = newNode(2);
    head2->next->next = newNode(4);
    Node* mergedhead = merge(head1, head2);
    printList(mergedhead);
    return 0;
}
