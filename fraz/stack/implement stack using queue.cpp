using namespace std;
#include <bits/stdc++.h>

// class MyStack {
//     queue<int> q1,q2;
// public:
//     MyStack(){}
//     void push(int x){
//         q2.push(x);
//         while(!q1.empty()) q2.push(q1.front()),q1.pop();
//         swap(q1,q2);
//     }
//     int pop(){
//         int result = top();
//         q1.pop();
//         return result;
//     }
//     int top(){
//         return q1.front();
//     }
//     bool empty(){
//         return q1.empty();
//     }
// };

class MyStack{
    queue<int> q;
    public:
    MyStack(){}
    void push(int x){
        int s = q.size();
        q.push(x);
        for (int i = 0; i < s; i++) q.push(q.front()),q.pop();
    }
    int pop(){
        int result = top();
        q.pop();
        return result;
    }
    int top(){
        return q.front();
    }
    bool empty(){
        return q.empty();
    }
};

int main(){
    //leet code solutions
    //https://leetcode.com/problems/implement-stack-using-queues/
    return 0;
}

