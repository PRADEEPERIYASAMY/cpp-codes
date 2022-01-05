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

Node *segregate(Node *head){
    Node *es = nullptr,*ee = nullptr,*os = nullptr, *oe = nullptr;
    for(Node *cur = head;cur != nullptr;cur = cur->next){
        int x = cur->data;
        if(x%2 == 0){
            if(es == nullptr){
                es = cur;
                ee = es;
            }else{
                ee->next = cur;
                ee=ee->next;
            }
        }else{
            if(os == nullptr){
                os = cur;
                oe = os;
            }else{
                oe->next = cur;
                oe = oe->next;
            }
        }
    }
    if(os == nullptr || es == nullptr) return head;
    ee->next = os;
    oe->next = nullptr;
    return es;
}

int main() { 
	Node *head=new Node(17);
	head->next=new Node(15);
	head->next->next=new Node(8);
	head->next->next->next=new Node(12);
	head->next->next->next->next=new Node(10);
	head->next->next->next->next->next=new Node(5);
	head->next->next->next->next->next->next=new Node(4);
	printlist(head);
	head=segregate(head);
	printlist(head);
	return 0;
}

