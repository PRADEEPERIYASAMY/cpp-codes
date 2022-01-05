#include <bits/stdc++.h> 
using namespace std; 

struct Node{
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=NULL;
    }
};

int getCount(Node *head){
    Node* cur = head;
    int count = 0;
    while(cur != nullptr){
        count++;
        cur = cur->next;
    }
    return count;
}

int _getIntersection(int d,Node* head1,Node *head2){
    Node* cur1 = head1;
    Node* cur2 = head2;
    for (int i = 0; i < d; i++) {
        if(cur1 == nullptr) return -1;
        cur1 = cur1->next;
    }
    while(cur1 != nullptr && cur2 != nullptr){
        if(cur2 == cur1) return cur1->data;
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    return -1;
}

int getIntersection(Node *head1, Node *head2){
    int c1 = getCount(head1);
    int c2 = getCount(head2);
    int d;
    if(c1>c2){
        d = c1-c2;
        return _getIntersection(d,head1,head2);
    }else{
        d = c2-c1;
        return _getIntersection(d,head2,head1);
    }
}

int main() { 
	Node* newNode; 
	Node* head1 = new Node(10); 
	Node* head2 = new Node(3); 
	newNode = new Node(6); 
	head2->next = newNode; 
	newNode = new Node(9); 
	head2->next->next = newNode; 
	newNode = new Node(15); 
	head1->next = newNode; 
	head2->next->next->next = newNode; 
	newNode = new Node(30); 
	head1->next->next = newNode; 
	head1->next->next->next = NULL; 
	cout <<getIntersection(head1, head2); 
	return 0;
} 

