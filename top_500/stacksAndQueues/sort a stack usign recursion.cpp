#include <bits/stdc++.h>
using namespace std;

void sortedInsert(stack<int> &st,int x){
    if(st.empty() or x>st.top()){
        st.push(x);
        return;
    }
    int temp = st.top();st.pop();
    sortedInsert(st,x);
    st.push(temp);
}

void sortStack(stack<int> &st){
    if(!st.empty()){
        int x = st.top();st.pop();
        sortStack(st);
        sortedInsert(st,x);
    }
}

void printStack(stack<int> st){
    while(!st.empty()){
        cout<<st.top()<<"\n";
        st.pop();
    }
    cout<<"\n";
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/sort-a-stack-using-recursion/
	stack<int> st;
	st.push(30),st.push(-5),st.push(18),st.push(14),st.push(-3);
	cout << "Stack elements before sorting:\n";
    printStack(st);
    sortStack(st);
    cout << "\n";
    cout << "Stack elements after sorting:\n";
    printStack(st);
    return 0;
}
