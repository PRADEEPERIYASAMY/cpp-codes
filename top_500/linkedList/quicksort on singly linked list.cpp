#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int new_data){
    struct Node* new_node = new Node;
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct Node* node){
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

Node *getTail(Node *headRef){
    while(headRef && headRef->next) headRef = headRef->next;
    return headRef;
}

Node *pratition(Node *head,Node *end,Node *&newHead,Node *&newEnd){
    Node *pivot = end;
    Node *prev = nullptr,*cur = head,*tail = pivot;
    while(cur != pivot){
        if(cur->data<pivot->data){
            if(newHead == nullptr) newHead = cur;
            prev = cur;
            cur = cur->next;
        }else{
            if(prev) prev->next = cur->next;
            Node *tmp = cur->next;
            cur->next = nullptr;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }
    if(newHead == nullptr) newHead = pivot;
    newEnd = tail;
    return pivot;
}

Node *quickSortRec(Node *head,Node *end){
    if(!head || head == end) return head;
    Node *newHead = nullptr,*newEnd = nullptr;
    Node *pivot = pratition(head,end,newHead,newEnd);
    if(newHead != pivot){
        Node *tmp = newHead;
        while(tmp->next != pivot) tmp = tmp->next;
        tmp->next = nullptr;
        newHead = quickSortRec(newHead,tmp);
        tmp = getTail(newHead);
        tmp->next = pivot;
    }
    pivot->next = quickSortRec(pivot->next,newEnd);
    return newHead;
}

void quickSort(Node *&headRef){
    headRef = quickSortRec(headRef,getTail(headRef));
    return;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/quicksort-on-singly-linked-list/
	struct Node* a = NULL;
    push(&a, 5);
    push(&a, 20);
    push(&a, 4);
    push(&a, 3);
    push(&a, 30);
    cout << "Linked List before sorting \n";
    printList(a);
    quickSort(a);
    cout << "Linked List after sorting \n";
    printList(a);
    return 0;
}
