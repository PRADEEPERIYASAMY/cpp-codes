#include <bits/stdc++.h> 
using namespace std; 

struct Node{
    int data;
    Node *next;
    Node(int d){
        data = d;
        next = nullptr;
    }
};

struct MyStack{
    Node *head;
    int size;
    MyStack(){
        head = nullptr;
        size = 0;
    }
    void push(int x){
        Node *temp = new Node(x);
        temp->next = head;
        head = temp;
        size++;
    }
    int pop(){
        if(head == nullptr){cout<<"Stack is Empty"<<endl;return INT_MAX;}
        int res = head->data;
        Node *temp = head;
        head = head->next;
        delete(temp);
        size--;
        return res;
    }
    int peek(){
        if(head==nullptr){cout<<"Stack is Empty"<<endl;return INT_MAX;}
        return head->data;
    }
    
    int getSize(){
        return size;
    }
    
    bool isEmpty(){
        return head==nullptr;
    }
};

int main() {
    MyStack s;
    s.push(5);
    s.push(10);
    s.push(20);
    cout<<s.pop()<<endl;
    cout<<s.getSize()<<endl;
    cout<<s.peek()<<endl;
    cout<<s.isEmpty()<<endl;
    return 0;
}

