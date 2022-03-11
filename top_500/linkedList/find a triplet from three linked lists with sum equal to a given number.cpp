#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void push (Node** head_ref, int new_data){
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// list b and c are assumed to be sorted acc and desc if not do it manually
bool isSumSorted(Node *headA,Node *headB,Node *headC,int givenNumber){
    Node *a = headA;
    while(a){
        Node *b = headB, *c = headC;
        while( b && c){
            int sum = a->data+b->data+c->data;
            if(sum == givenNumber){
                cout<<"Triplet found: "<<a->data<<" "<<b->data<<" "<<c->data<<"\n";
                return true;
            }else if(sum<givenNumber) b = b->next;
            else c = c->next;
        }
        a = a->next;
    }
    cout<<"No such triplet\n";
    return false;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/find-a-triplet-from-three-linked-lists-with-sum-equal-to-a-given-number/
	Node* headA = NULL;
    Node* headB = NULL;
    Node* headC = NULL;
    push (&headA, 20);
    push (&headA, 4);
    push (&headA, 15);
    push (&headA, 10);
    push (&headB, 10);
    push (&headB, 9);
    push (&headB, 4);
    push (&headB, 2);
    push (&headC, 1);
    push (&headC, 2);
    push (&headC, 4);
    push (&headC, 8);
    int givenNumber = 25;
    isSumSorted (headA, headB, headC, givenNumber);
    return 0;
}
