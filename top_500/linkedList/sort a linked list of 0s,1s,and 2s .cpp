#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void sortList(Node *head){
    int count[3]={0};
    Node *ptr = head;
    while(ptr){
        count[ptr->data]++;
        ptr = ptr->next;
    }
    int i = 0;
    ptr = head;
    while(ptr){
        if(count[i] == 0) i++;
        else{
            ptr->data = i;
            count[i]--;
            ptr = ptr->next;
        }
    }
}

void push (Node** head_ref, int new_data){
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
 

void printList(Node *node){
    while (node != NULL){
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/sort-a-linked-list-of-0s-1s-or-2s/
	Node *head = NULL;
    push(&head, 0);
    push(&head, 1);
    push(&head, 0);
    push(&head, 2);
    push(&head, 1);
    push(&head, 1);
    push(&head, 2);
    push(&head, 1);
    push(&head, 2);
    cout << "Linked List Before Sorting\n";
    printList(head);
    sortList(head);
    cout << "Linked List After Sorting\n";
    printList(head);
    return 0;
}
