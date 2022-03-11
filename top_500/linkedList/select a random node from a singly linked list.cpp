#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int key;
    Node* next;
    void printRandom(Node*);
    void push(Node**, int);
};

Node* newNode(int new_key){
    Node* new_node = (Node*) malloc(sizeof( Node));
    new_node->key = new_key;
    new_node->next = NULL;
    return new_node;
}

void Node:: push(Node** head_ref, int new_key){
    Node* new_node = new Node;
    new_node->key = new_key;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void Node::printRandom(Node *head){
    if(head == nullptr) return;
    srand(time(NULL));
    int result = head->key;
    Node *current = head;
    for (int i = 2; current != nullptr; i++) {
        if(rand()%i == 0) result = current->key;
        current = current->next;
    }
    cout<<"randomly selected key is \n"<<result;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/select-a-random-node-from-a-singly-linked-list/
	Node n1;
    Node *head = NULL;
    n1.push(&head, 5);
    n1.push(&head, 20);
    n1.push(&head, 4);
    n1.push(&head, 3);
    n1.push(&head, 30);
    n1.printRandom(head);
    return 0;
}
