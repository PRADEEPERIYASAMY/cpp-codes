#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

Node* newNode(int data){
    Node* temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void printList(struct Node* Node){
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

int getLength(Node *node){
    int size = 0;
    while(node){
        node = node->next;
        size++;
    }
    return size;
}

Node *paddZeroes(Node *sNode,int diff){
    if(sNode == nullptr) return nullptr;
    Node *zHead = newNode(0);
    diff--;
    Node *temp = zHead;
    while(diff--){
        temp->next = newNode(0);
        temp = temp->next;
    }
    temp->next = sNode;
    return zHead;
}

Node *subtractLinkedListHelper(Node *l1,Node *l2, bool &borrow){
    if(l1 == nullptr && l2 == nullptr && !borrow ) return nullptr;
    Node *previous = subtractLinkedListHelper(l1?l1->next:nullptr,l2?l2->next:nullptr,borrow);
    int d1 = l1->data,d2 = l2->data;
    int sub = 0;
    if(borrow){
        d1--;
        borrow = false;
    }
    if(d1<d2){
        borrow = true;
        d1+=10;
    }
    sub = d1 - d2;
    Node *current = newNode(sub);
    current->next = previous;
    return current;
}

Node *subtractLinkedList(Node *l1,Node *l2){
    if(l1 == nullptr && l2 == nullptr) return nullptr;
    int len1 = getLength(l1),len2 = getLength(l2);
    Node *lNode = nullptr,*sNode = nullptr;
    Node *temp1 = l1,*temp2 = l2;
    if(len1 != len2){
        lNode = len1>len2?l1:l2;
        sNode = len1>len2?l2:l1;
        sNode = paddZeroes(sNode,abs(len1 - len2));
    }else{
        while(l1 && l2){
            if(l1->data != l2->data){
                lNode = l1->data > l2->data?temp1:temp2;
                sNode = l1->data > l2->data?temp2:temp1;
                break;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
    }
    if(lNode == nullptr && sNode == nullptr) return newNode(0);
    bool borrow = false;
    return subtractLinkedListHelper(lNode,sNode,borrow);
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/subtract-two-numbers-represented-as-linked-lists/
	Node* head1 = newNode(1);
    head1->next = newNode(0);
    head1->next->next = newNode(0);
    Node* head2 = newNode(1);
    Node* result = subtractLinkedList(head1, head2);
    printList(result);
    return 0;
}
