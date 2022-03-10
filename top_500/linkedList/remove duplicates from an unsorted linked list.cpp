#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

// alterante option is use mergesort and then remove dulpicates - nlogn 

struct Node* newNode(int data){
    Node* temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void printList(struct Node* node){
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

// using hashing
void removeDuplicates(Node *start){
    unordered_set<int> visited;
    Node *cur = start;
    Node *prev = nullptr;
    while(cur != nullptr){
        if(visited.find(cur->data) != visited.end()){
            prev->next = cur->next;
            delete(cur);
        }else{
            visited.insert(cur->data);
            prev = cur;
        }
        cur = prev->next;
    }
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/remove-duplicates-from-an-unsorted-linked-list/
	struct Node* start = newNode(10);
    start->next = newNode(12);
    start->next->next = newNode(11);
    start->next->next->next = newNode(11);
    start->next->next->next->next = newNode(12);
    start->next->next->next->next->next = newNode(11);
    start->next->next->next->next->next->next = newNode(10);
    printf("Linked list before removing duplicates : \n");
    printList(start);
    removeDuplicates(start);
    printf("\nLinked list after removing duplicates : \n");
    printList(start);
    return 0;
}
