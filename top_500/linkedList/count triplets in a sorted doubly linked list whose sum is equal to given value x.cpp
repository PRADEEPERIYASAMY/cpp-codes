#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next, *prev;
};

void insert(struct Node** head, int data){
    struct Node* temp = new Node();
    temp->data = data;
    temp->next = temp->prev = NULL;
    if ((*head) == NULL)(*head) = temp;
    else {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}

// naive method
// int countTriplets(Node *head,int x){
//     Node * ptr1,*ptr2,ptr3;
//     int count = 0;
//     for (ptr1 = head; ptr1 != nullptr; ptr1 = ptr1->next) {
//         for (ptr2 = ptr1->next; ptr2 != nullptr; ptr2 = ptr2->next) {
//             for (ptr3 = ptr2->next; ptr3 != nullptr; ptr3 = ptr3->next) {
//                 if(ptr1->data + ptr2->data + ptr3->data == x) count++;
//             }
//         }
//     }
//     return count;
// }

// using hashing
// int countTriplets(Node *head,int x){
//     Node *ptr,*ptr1,*ptr2;
//     int count = 0;
//     unordered_map<int,Node*> um;
//     for (ptr = head; ptr != nullptr; ptr = ptr->next) um[ptr->data] = ptr;
//     for (ptr1 = head; ptr1 != nullptr; ptr1 = ptr1->next) {
//         for (ptr2 = ptr1->next; ptr2 != nullptr; ptr2 = ptr2->next) {
//             int psum = ptr1->data+ptr2->data;
//             if(um.find(x-psum) != um.end() && um[x-psum] != ptr1 && um[x - psum] != ptr2) count++;
//         }
//     }
//     return count/3;
// }

// using two pointer
int countPairs(Node *first,Node *last,int x){
    int count = 0;
    while(first != nullptr && last != nullptr && first != last && first != last->next ){
        if(first->data + last->data == x){
            count++;
            first = first->next;
            last = last->prev;
        }else if(first->data + last->data <x) first = first->next;
        else last = last->prev;
    }
    return count;
}

int countTriplets(Node *head,int x){
    if(head == nullptr) return 0;
    Node *current,*first,*last;
    int count = 0;
    last = head;
    while(last->next) last = last->next;
    for (current = head; current != nullptr; current = current->next) {
        first = current->next;
        count+=countPairs(first,last,x - current->data);
    }
    return count;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/count-triplets-sorted-doubly-linked-list-whose-sum-equal-given-value-x/
	struct Node* head = NULL;
    insert(&head, 9);
    insert(&head, 8);
    insert(&head, 6);
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 2);
    insert(&head, 1);
    int x = 17;
    cout << "Count = "<< countTriplets(head, x);
    return 0;
}
