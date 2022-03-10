#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int data):data(data){
        next = nullptr;
    }
};

// deleting only head case
// not acceptable since it is not deleting the node
void deleteNode(Node *node){
    Node *prev;
    if(node == nullptr) return;
    while(node->next != nullptr){
        node->data = node->next->data;
        prev = node;
        node = node->next;
    }
    prev->next = nullptr;
}

void printList(Node *head){
    Node* temp = head;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/given-only-a-pointer-to-a-node-to-be-deleted-in-a-singly-linked-list-how-do-you-delete-it/
	Node *head = new Node(1);
	head->next = new Node(4);
	head->next->next = new Node(1);
	head->next->next->next = new Node(12);
	head->next->next->next->next = new Node(1);
	cout<<"Before deleting \n";
	printList(head);
	deleteNode(head);
	cout<<"After deleting \n";
	printList(head);
    return 0;
}
