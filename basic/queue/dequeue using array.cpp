#include <bits/stdc++.h> 
using namespace std; 

struct DeQueue{
    int *arr;
    int front,size,capacity;
    DeQueue(int c){
        capacity = c;
        size = 0;
        front = 0;
        arr = new int[c];
    }
    
    bool isFull(){
        return size == capacity;
    }
    bool isEmpty(){
        return size == 0;
    }
    
    void deleteFront(){
        if(isEmpty()) return;
        front = (front+1)%capacity;
        size--;
    }
    
    void insertFront(int x){
        if(isFull()) return;
        front = (front+capacity-1)%capacity; //insert at back
        arr[front] = x;
        size++;
    }
    void insertRear(int x){
        if(isFull()) return ;
        int rear = (front+size)%capacity; // inset at first
        arr[rear] = x;
        size++;
    }
    void deleteRear(){
        if(isEmpty()) return;
        size--;
    }
    int getFront(){
        if(isEmpty()) return INT_MIN;
        return arr[front];
    }
    int getRear(){
        if(isEmpty()) return INT_MIN;
        return arr[(front+size-1)%capacity];
    }
};

int main() {
	DeQueue q = DeQueue(1000); 
	q.insertFront(10); 
	q.insertRear(20); 
	q.insertFront(30); 
	q.insertFront(40); 
	q.insertRear(50); 
	q.deleteRear(); 
	cout << "Queue Front : " << q.getFront() << endl; 
	cout << "Queue Rear : " << q.getRear();
	return 0;
}

