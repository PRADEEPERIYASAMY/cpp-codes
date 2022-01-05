#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

struct Node{
    Node* next;
    int data;
    Node(int x){
        data = x;
        next = nullptr;
    }
};

void printList(struct Node* node){
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

void removeDuplicates(Node *start){
    unordered_set<int> s;
    Node *curr = start;
    Node *prev = nullptr;
    while(curr != nullptr){
        if(s.find(curr->data) != s.end()){
            prev->next = curr->next;
            delete(curr);
        }else{
            s.insert(curr->data);
            prev = curr;
        }
        curr = prev->next;
    }
}

int main() {
    struct Node* start = new Node(10);
    start->next = new Node(12);
    start->next->next = new Node(11);
    start->next->next->next = new Node(11);
    start->next->next->next->next = new Node(12);
    start->next->next->next->next->next = new Node(11);
    start->next->next->next->next->next->next = new Node(10);
    printf("Linked list before removing duplicates : \n");
    printList(start);
    removeDuplicates(start);
    printf("\nLinked list after removing duplicates : \n");
    printList(start);
    return 0;
}

