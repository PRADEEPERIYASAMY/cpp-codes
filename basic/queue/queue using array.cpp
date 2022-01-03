#include <bits/stdc++.h> 
using namespace std; 

class Queue{
    public:
    int front,rear,size;
    unsigned int capacity;
    int *array;
    Queue(unsigned int capacity){
        this->capacity = capacity;
        front =size= 0;
        rear = capacity-1;
        array = new int[capacity];
    }
    bool isFull(){
        return size == capacity;
    }
    bool isEmpty(){
        return size == 0;
    }
    void enqueue(int item){
        if(isFull()) return;
        rear = (rear+1)%capacity;
        array[rear] = item;
        size++;
        cout<<item<<" enqueued"<<" ";
    }
    int dequeue(){
        if(isEmpty())return INT_MIN;
        int item = array[front];
        front = (front+1)%capacity;
        size--;
        return item;
    }
    int Gfront(){
        if(isEmpty()) return INT_MIN;
        return array[front];
    }
    int Grear(){
        if(isEmpty()) return INT_MIN;
        return array[rear];
    }
};

int main() {
	Queue* queue = new Queue(1000); 
	queue->enqueue(10);
	queue->enqueue(20);
	queue->enqueue(30);
	queue->enqueue(40);
	cout << queue->dequeue() << " dequeued from queue\n"; 
	cout << "Front item is "<< queue->Gfront() << endl; 
	cout << "Rear item is "<< queue->Grear()<< endl;
	return 0;
}

