#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pi;

class Stack{
    int cnt;
    priority_queue<pi> pq;
    public:
    Stack():cnt(0){};
    void push(int n){
        cnt++;
        pq.push({cnt,n});
    }
    void pop(){
        if(pq.empty()){
            cout<<"Nothing to pop\n";
            return;
        }
        cnt--;
        pq.pop();
    }
    int top(){
        return pq.top().second;
    }
    bool isEmpty(){
        return pq.empty();
    }
};

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/implement-stack-using-priority-queue-or-heap/
	Stack* s=new Stack();
    s->push(1);
    s->push(2);
    s->push(3);
    while(!s->isEmpty()){
        cout<<s->top()<<endl;
        s->pop();
    }

    return 0;
}
