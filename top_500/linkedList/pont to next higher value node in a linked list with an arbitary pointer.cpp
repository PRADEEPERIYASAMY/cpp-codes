#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next, *arbit;
};

void frontBackSplit(Node *source,Node *&frontRef,Node *&backRef){
    Node *fast,*slow;
    if(source == nullptr || source->arbit == nullptr){
        frontRef = source;
        backRef = nullptr;
        return;
    }
    slow = source,fast = source->arbit;
    while(fast != nullptr){
        fast = fast->arbit;
        if(fast != nullptr) fast = fast->arbit,slow = slow->arbit;
    }
    frontRef = source;
    backRef = slow->arbit;
    slow->arbit = nullptr;
}

Node *sortedMerge(Node *a,Node *b){
    Node *result = nullptr;
    if(a == nullptr) return b;
    else if(b == nullptr) return a;
    if(a->data <= b->data){
        result = a;
        result->arbit = sortedMerge(a->arbit,b);
    }else{
        result = b;
        result->arbit = sortedMerge(a,b->arbit);
    }
    return result;
}

void mergesort(Node *&headRef){
    Node *head = headRef;
    Node *a,*b;
    if(head == nullptr || head->arbit == nullptr) return;
    frontBackSplit(head,a,b);
    mergesort(a);
    mergesort(b);
    headRef = sortedMerge(a,b);
}

Node *populateArbit(Node *head){
    Node *temp = head;
    while(temp != nullptr){
        temp->arbit = temp->next;
        temp = temp->next;
    }
    mergesort(head);
    return head;
}

void printListafter(Node *node, Node *anode){
    cout<<"Traversal using Next Pointer\n";
    while (node!=NULL){
        cout << node->data << ", ";
        node = node->next;
    }
    printf("\nTraversal using Arbit Pointer\n");
    while (anode!=NULL){
        cout << anode->data << ", ";
        anode = anode->arbit;
    }
}

void push(Node** head_ref, int new_data){
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    new_node->arbit = NULL;
    (*head_ref) = new_node;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/point-to-next-higher-value-node-in-a-linked-list-with-an-arbitrary-pointer/
	Node* head = NULL;
    push(&head, 3);
    push(&head, 2);
    push(&head, 10);
    push(&head, 5);
    Node *ahead = populateArbit(head);
    cout << "Result Linked List is: \n";
    printListafter(head, ahead);
    return 0;
}
