#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void push(Node** head_ref, int new_data){
    Node* new_node = new Node;
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
 
void printList(Node* node){
    while (node != NULL){
        cout << node->data << " ";
        node = node->next;
    }
}

Node *rotateHelper(Node *blockHead,Node *blockTail,int d,Node *&tail,int k){
    if(d == 0) return blockHead;
    if(d > 0){
        Node *temp = blockHead;
        for (int i = 1; temp->next->next && i < k-1 ; i++) temp = temp->next;
        blockTail->next = blockHead;
        tail = temp;
        return rotateHelper(blockTail,temp,d-1,tail,k);
    }
    if(d<0){
        blockTail->next = blockHead;
        tail = blockHead;
        return rotateHelper(blockHead->next,blockHead,d+1,tail,k);
    }
}

Node *rotateByBlocks(Node *head,int k,int d){
    if(!head || !head->next) return head;
    if(d == 0) return head;
    Node *temp = head,*tail = nullptr;
    int i;
    for (i = 1;temp->next && i < k; i++) temp = temp->next;
    Node *nextBlock = temp->next;
    if(i<k) head = rotateHelper(head,temp,d%k,tail,i);
    else head = rotateHelper(head,temp,d%k,tail,k);
    tail->next = rotateByBlocks(nextBlock,k,d%k);
    return head;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/rotate-linked-list-block-wise/
	Node* head = NULL;
    for (int i = 9; i > 0; i -= 1)push(&head, i);
    cout<<"Given linked list \n";
    printList(head);
    int k = 3, d = 2;
    head = rotateByBlocks(head, k, d);
    cout << "\nRotated by blocks Linked list \n";
    printList(head);
    return 0;
}
