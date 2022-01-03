#include <bits/stdc++.h> 
using namespace std; 

struct QNode{
    int data;
    QNode *next;
    QNode(int data){
        this->data = data;
        next = nullptr;
    }
};

class Queue{
    public:
    QNode *front,*rear;
    Queue(){
        front =rear = nullptr;
    }
 
    void enqueue(int item){
        QNode *temp = new QNode(item);
        if(rear == nullptr){
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = rear->next;
    }
    void dequeue(){
        if(front == nullptr) return;
        QNode *temp = front;
        front = front->next;
        if(front == nullptr) rear = nullptr;
        delete(temp);
    }
};

int main() {
	Queue q; 
	q.enqueue(10); 
	q.enqueue(20); 
	q.dequeue(); 
	q.dequeue(); 
	q.enqueue(30); 
	q.enqueue(40); 
	q.enqueue(50); 
	q.dequeue(); 
	cout << "Queue Front : " << (q.front)->data << endl; 
	cout << "Queue Rear : " << (q.rear)->data;
	return 0;
}

