#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int new_data){
    struct Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printNthFromLast(struct Node* head, int n){
    Node *first,*second;
    first = second = head;
    if(head == nullptr){
        cout<<"List is empty "<<endl;
        return;
    }
    for (int i = 1; i < n; i++) {
        first = first->next;
        if(first == nullptr){
            cout<<"n is greater than no of nodes in the list\n";
            return;
        }
    }
    while(first != nullptr && first->next != nullptr){
        first = first->next;
        second = second->next;
    }
    cout<<"Node no "<<n<<" from end is: "<<second->data<<"\n";
}

void displaylist(Node *head){
        while (head != NULL) {
            cout << head->data << "->";
            head = head->next;
        }
        cout << "NULL" << endl;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/nth-node-from-the-end-of-a-linked-list/
	struct Node* head = NULL;
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);
    push(&head, 50);
    push(&head, 60);
    displaylist(head);
    printNthFromLast(head, 1);
    return 0;
}
