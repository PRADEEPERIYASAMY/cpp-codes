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

int countNodes(Node *head){
    int res = 1;
    Node *temp = head;
    while(temp->next != head){
        res++;
        temp=temp->next;
    }
    return res;
}

int countNodesinLoop(Node *head){
    Node *slow = head,*fast = head;
    while(slow && fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return countNodes(slow);
    }
    return 0;
}

int main() {
	struct Node *head = new Node(1); 
    head->next = new Node(2); 
    head->next->next = new Node(3); 
    head->next->next->next = new Node(4); 
    head->next->next->next->next = new Node(5); 
    head->next->next->next->next->next = head->next; 
    cout << countNodesinLoop(head) << endl; 
	return 0;
}

