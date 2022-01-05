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

void printlist(Node *head){
    Node *curr=head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }cout<<endl;
}

Node *reverseK(Node *head,int k){
    Node *curr=head,*firstPrev = nullptr;
    bool isFirstPass = true;
    while(curr != nullptr){
        Node *first = curr,*prev = nullptr;
        int count = 0;
        while(curr != nullptr && count<k){
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if(isFirstPass){head = prev;isFirstPass = false;}
        else{firstPrev->next = first;}
        firstPrev = first;
    }
    return head;
}

int main() 
{ 
	Node *head=new Node(10);
	head->next=new Node(20);
	head->next->next=new Node(30);
	head->next->next->next=new Node(40);
	head->next->next->next->next=new Node(50);
	head->next->next->next->next->next=new Node(60);
	head->next->next->next->next->next->next=new Node(70);
	printlist(head);
	head=reverseK(head,3);
	printlist(head);
	return 0;
} 

