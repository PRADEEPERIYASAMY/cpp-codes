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

bool isPalindrome(Node *head){
    stack<char> st;
    for(Node *curr=head;curr !=nullptr;curr = curr->next)st.push(curr->data);
    for(Node *curr = head;curr != nullptr;curr = curr->next){
        if(st.top()!= curr->data) return false;
        st.pop();
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

