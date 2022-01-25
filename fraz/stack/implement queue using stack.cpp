using namespace std;
#include <bits/stdc++.h>

class MyQueue {
    stack<int> st;
    public:
    MyQueue(){}
    
    void push(int x){
        stack<int> temp;
        while(!st.empty())temp.push(st.top()),st.pop();
        st.push(x);
        while(!temp.empty())st.push(temp.top()),temp.pop();
    }
    int pop(){
        int val = st.top();st.pop();
        return val;
    }
    int peek(){
        return st.top();
    }
    bool empty(){
        return st.empty();
    }
};

int main(){
    //leet code solutions
    //https://leetcode.com/problems/implement-queue-using-stacks/
    return 0;
}

