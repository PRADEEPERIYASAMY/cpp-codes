#include <bits/stdc++.h> 
using namespace std; 

struct Node{
    int data;
    Node *prev,*next;
    Node(int d){
        data = d;
        prev = next = nullptr;
    }
};

struct DeQueue{
    int size;
    Node *front,*rear;
    DeQueue(){
        front = rear = nullptr;
        size = 0;
    }
    
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size == 0;
    }
    
    void deleteFront(){
        if (isEmpty())
        cout << "UnderFlow\n";
        else{
            Node* temp = front;
            front = front->next;
            if (front == nullptr) rear = nullptr;
            else front->prev = nullptr;
            delete(temp);
            size--;
        }
    }
    
    void insertFront(int x){
        Node *temp = new Node(x);
        if(temp == nullptr) cout<<"overflow"<<endl;
        else{
            if(front == nullptr) rear = front = temp;
            else{
                temp->next = front;
                front->prev = temp;
                front = temp;
            }
        }
        size++;
    }
    void insertRear(int x){
        Node *temp = new Node(x);
        if(temp == nullptr) cout<<"overflow"<<endl;
        else{
            if(rear == nullptr) front = rear = temp;
            else{
                temp->prev = rear;
                rear->next = temp;
                rear = temp;
            }
        }
        size++;
    }
    void deleteRear(){
        if(isEmpty()) cout<<"UnderFlow\n";
        else{
            Node *temp = rear;
            rear = rear->prev;
            if(rear == nullptr) front = nullptr;
            else rear->next = nullptr;
            delete(temp);
            size--;
        }
    }
    int getFront(){
        if(isEmpty()) return INT_MIN;
        return front->data;
    }
    int getRear(){
        if(isEmpty()) return INT_MIN;
        return rear->data;
    }
    void erase(){
        rear = nullptr;
        while (front != nullptr){
            Node* temp = front;
            front = front->next;
            delete(temp);
        }
        size = 0;
    }
};

int main() {
	DeQueue dq = DeQueue(); 
	cout << "Insert element '5' at rear end\n";
	dq.insertRear(5);
    cout << "Insert element '10' at rear end\n";
    dq.insertRear(10);
    cout << "Rear end element: "<< dq.getRear() << endl;
    dq.deleteRear();
    cout << "After deleting rear element new rear"<< " is: " << dq.getRear() << endl;
    cout << "Inserting element '15' at front end \n";
    dq.insertFront(15);
    cout << "Front end element: "<< dq.getFront() << endl;
    cout << "Number of elements in Deque: "<< dq.getSize() << endl;
    dq.deleteFront();
    cout << "After deleting front element new "<< "front is: " << dq.getFront() << endl;
	return 0;
}

