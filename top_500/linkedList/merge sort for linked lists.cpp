#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

void frontBackSplit(Node *source,Node *&frontRef,Node *&backRef){
    Node *fast,*slow;
    slow = source;
    fast = source->next;
    while(fast != nullptr && fast->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;
    }
    frontRef = source;
    backRef = slow->next;
    slow->next = nullptr;
}

Node *sortedMerge(Node *a,Node *b){
    Node *result = nullptr;
    if(a == nullptr) return b;
    if(b == nullptr) return a;
    if(a->data <= b->data){
        result = a;
        result->next = sortedMerge(a->next,b);
    }else{
        result = b;
        result->next = sortedMerge(a,b->next);
    }
    return result;
}

void printList(Node* node){
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}

void MergeSort(Node *&headRef){
    Node *head = headRef;
    Node *a,*b;
    if(head == nullptr || head->next == nullptr) return;
    frontBackSplit(head,a,b);
    MergeSort(a);
    MergeSort(b);
    headRef = sortedMerge(a,b);
}

void push(Node** head_ref, int new_data){
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/merge-sort-for-linked-list/
	Node* res = NULL;
    Node* a = NULL;
    push(&a, 15);
    push(&a, 10);
    push(&a, 5);
    push(&a, 20);
    push(&a, 3);
    push(&a, 2);
    MergeSort(a);
    cout << "Sorted Linked List is: \n";
    printList(a);
    return 0;
}
