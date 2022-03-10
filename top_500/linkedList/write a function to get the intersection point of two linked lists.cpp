#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

//first method use hashmap

// distance method
// int getCount(Node *head){
//     int count = 0;
//     while(head != nullptr){
//         count++;
//         head = head->next;
//     }
//     return count;
// }

// int _getIntesectionNode(int d,Node *head1,Node *head2){
//     for (int i = 0; i < d; i++) {
//         if(head1 == nullptr) return -1;
//         head1 = head1->next;
//     }
//     while(head1 != nullptr && head2 != nullptr){
//         if(head1 == head2) return head1->data;
//         head1 = head1->next;
//         head2 = head2->next;
//     }
//     return -1;
// }

// int getIntesectionNode(Node *head1,Node *head2){
//     int c1 = getCount(head1),c2 = getCount(head2);
//     int d = abs(c1 - c2);
//     if(c1>c2) return _getIntesectionNode(d,head1,head2);
//     else return _getIntesectionNode(d,head2,head1);
// }

// two pointer method
int getIntesectionNode(Node *head1,Node *head2){
    Node *ptr1 = head1,*ptr2 = head2;
    if(ptr1 == nullptr || ptr2 == nullptr) return -1;
    while(ptr1 != ptr2){
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
        if(ptr1 == ptr2) return ptr1->data;
        if(ptr1 == nullptr) ptr1 = head2;
        if(ptr2 == nullptr) ptr2 = head1;
    }
    return ptr1->data;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/write-a-function-to-get-the-intersection-point-of-two-linked-lists/
    Node* newNode;
    Node* head1 = new Node();
    head1->data = 10;
    Node* head2 = new Node();
    head2->data = 3;
    newNode = new Node();
    newNode->data = 6;
    head2->next = newNode;
    newNode = new Node();
    newNode->data = 9;
    head2->next->next = newNode;
    newNode = new Node();
    newNode->data = 15;
    head1->next = newNode;
    head2->next->next->next = newNode;
    newNode = new Node();
    newNode->data = 30;
    head1->next->next = newNode;
    head1->next->next->next = NULL;
    cout << "The node of intersection is " << getIntesectionNode(head1, head2);
    return 0;
}
