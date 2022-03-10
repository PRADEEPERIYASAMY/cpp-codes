#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

Node* addList(Node *l1,Node *l2){
    stack<int> s1,s2;
    while(l1){
        s1.push(l1->data);
        l1 = l1->next;
    }
    while(l2){
        s2.push(l2->data);
        l2 = l2->next;
    }
    int carry = 0;
    Node *result = nullptr;
    while(!s1.empty() || !s2.empty()){
        int a,b;
        a = b = 0;
        if(!s1.empty()){
            a = s1.top();
            s1.pop();
        }
        if(!s2.empty()){
            b = s2.top();
            s2.pop();
        }
        int total = a+b+carry;
        Node *temp = new Node();
        temp->data = total%10;
        carry = total/10;
        if(result == nullptr) result = temp;
        else temp->next = result,result = temp;
    }
    if(carry != 0){
        Node *temp = new Node();
        temp->data = carry;
        temp->next = result;
        result = temp;
    }
    return result;
}

void push(struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct Node *node){
    while (node!=NULL){
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/sum-of-two-linked-lists/
	Node *head1 = NULL, *head2 = NULL, *result = NULL;
    int arr1[] = { 9, 9, 9 };
    int arr2[] = { 1, 8 };
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int i;
    for (i = size1 - 1; i >= 0; --i) push(&head1, arr1[i]);
    for (i = size2 - 1; i >= 0; --i) push(&head2, arr2[i]);
    result = addList(head1, head2);
    printList(result);
    return 0;
}
