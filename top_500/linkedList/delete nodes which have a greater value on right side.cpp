#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

// using reverse method

// void reverseList(Node *&head_ref){
//     Node *current = head_ref;
//     Node *prev = nullptr;
//     Node *next;
//     while(current != nullptr){
//         next = current->next;
//         current->next = prev;
//         prev = current;
//         current = next;
//     }
//     head_ref = prev;
// }

// void _delLesserNodes(Node *head){
//     Node *current = head;
//     Node *maxNode = head;
//     Node *temp;
//     while(current != nullptr && current->next != nullptr){
//         if(current->next->data <maxNode->data){
//             temp = current->next;
//             current->next = temp->next;
//             delete(temp);
//         }else{
//             current = current->next;
//             maxNode = current;
//         }
//     }
// }

// void delLesserNodes(Node *&head_ref){
//     reverseList(head_ref);
//     _delLesserNodes(head_ref);
//     reverseList(head_ref);
// }

// delete with recursion
Node* delLesserNodes(Node *&head_ref){
    if(head_ref == nullptr || head_ref->next == nullptr) return head_ref;
    Node *nextNode = delLesserNodes(head_ref->next);
    if(nextNode->data >head_ref->data) return nextNode;
    head_ref->next = nextNode;
    return head_ref;
}

void push(struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void printList(struct Node* head){
    while (head != NULL){
        cout << " " << head->data ;
        head = head->next;
    }
    cout << "\n" ;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/delete-nodes-which-have-a-greater-value-on-right-side/
	struct Node* head = NULL;
    push(&head, 3);
    push(&head, 2);
    push(&head, 6);
    push(&head, 5);
    push(&head, 11);
    push(&head, 10);
    push(&head, 15);
    push(&head, 12);
    cout << "Given Linked List \n" ;
    printList(head);
    //delLesserNodes(head);
    head = delLesserNodes(head);
    cout << "Modified Linked List \n" ;
    printList(head);
    return 0;
}
