#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

void insert(struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

Node *XOR(Node *a,Node *b){
    return (Node*)((uintptr_t)(a)^(uintptr_t)(b));
}

void  convert(Node *head){
    Node *nextNode,*prev = nullptr;
    while(head != nullptr){
        nextNode = head->next;
        head->next = XOR(nextNode,prev);
        prev = head;
        head = nextNode;
    }
}

void pairSum(Node *head,int x){
    Node *first = head;
    Node *nextNode = nullptr,*prev = nullptr;
    Node *second = head;
    while(second->next != prev){
        Node *temp = second;
        second = XOR(second->next,prev);
        prev = temp;
    }
    nextNode = nullptr,prev = nullptr;
    bool flag = false;
    while(first != nullptr && second != nullptr && first != second && first != nextNode){
        if(first->data + second->data == x){
            cout<<"( "<<first->data<<","<<second->data<<" )\n";
            flag = true;
            Node *temp = first;
            first = XOR(first->next,prev);
            prev = temp;
            
            temp = second;
            second = XOR(second->next,nextNode);
            nextNode = temp;
        }else{
            if(first->data + second->data <x ){
                Node *temp = first;
                first = XOR(first->next,prev);
                prev = temp;
            }else{
                Node *temp = second;
                second = XOR(second->next,nextNode);
                nextNode = temp;
            }
        }
    }
    if(flag == false) cout<<"No pair found"<<"\n";
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/find-pair-given-sum-sorted-singly-linked-without-extra-space/
	struct Node* head = NULL;
    int x = 17;
    insert(&head, 11);
    insert(&head, 10);
    insert(&head, 9);
    insert(&head, 8);
    insert(&head, 7);
    insert(&head, 6);
    insert(&head, 3);
    convert(head);
    pairSum(head,x);
    return 0;
}
