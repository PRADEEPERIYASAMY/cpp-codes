#include <bits/stdc++.h>
using namespace std;

class KQueues{
    int *arr,*front,*rear,*next,n,k,free;
    public:
    KQueues(int k,int n):k(k),n(n){
        arr = new int[n];
        front = new int[k];
        rear = new int[k];
        next = new int [n];
        fill(front,front+k,-1);
        free = 0;
        for (int i = 0; i <n-1; i++) next[i] = i+1;
        next[n-1] = -1;
    }
    
    void enqueue(int item,int qn){
        if(isfull()){
            cout<<"\nQueue overflow\n";
            return;
        }
        int i =free;
        free = next[i];
        if(isempty(qn)) front[qn] = i;
        else next[rear[qn]] = i;
        next[i] = -1;
        rear[qn] = i;
        arr[i] = item;
    }
    
    int dequeue(int qn){
        if(isempty(qn)){
            cout<<"\nQueue underflow\n";
            return INT_MAX;
        }
        int i = front[qn];
        front[qn] = next[i];
        next[i] = free;
        free = i;
        return arr[i];
    }
    
    bool isempty(int qn) {
        return (front[qn] == -1);
    }
    
    bool isfull() {
        return free == -1;
    }
};

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/efficiently-implement-k-queues-single-array/
	int k = 3, n = 10;
    KQueues ks(k, n);
    ks.enqueue(15, 2);
    ks.enqueue(45, 2);
    ks.enqueue(17, 1);
    ks.enqueue(49, 1);
    ks.enqueue(39, 1);
    ks.enqueue(11, 0);
    ks.enqueue(9, 0);
    ks.enqueue(7, 0);
    cout << "Dequeued element from queue 2 is " << ks.dequeue(2) << endl;
    cout << "Dequeued element from queue 1 is " << ks.dequeue(1) << endl;
    cout << "Dequeued element from queue 0 is " << ks.dequeue(0) << endl;
    return 0;
}