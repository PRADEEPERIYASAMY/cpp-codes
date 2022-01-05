#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

struct Node{
    Node* next;
    int data;
    Node(int x){
        data = x;
        next = nullptr;
    }
};

Node *reverseList(Node *head){
    if(head==NULL||head->next==NULL)return head;
    Node *rest_head=reverseList(head->next);
    Node *rest_tail=head->next;
    rest_tail->next=head;
    head->next=NULL;
    return rest_head;
}

bool isPalindrome(Node *head){
    if(head == nullptr) return true;
    Node *slow=head,*fast=head;
    while(fast->next != nullptr && fast->next->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *rev = reverseList(slow->next);
    Node *cur = head;
    while(rev != nullptr){
        if(rev->data != cur->data) return false;
        rev = rev->next;
        cur = cur->next;
    }
    return true;
}

int main() {
    Node *head=new Node('g');
	head->next=new Node('f');
	head->next->next=new Node('g');
	if(isPalindrome(head)) cout<<"Yes";
	else cout<<"No";
	return 0;
}

