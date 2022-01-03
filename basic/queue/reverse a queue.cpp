#include <bits/stdc++.h> 
using namespace std; 

void Print(queue<int> &q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}
// recursive
// void reverse(queue<int> &q){
//     if(q.empty()) return;
//     int x = q.front();
//     q.pop();
//     reverse(q);
//     q.push(x);
// }

// iterative
void reverse(queue<int> &q){
    stack<int> s;
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
}

int main() {
	queue<int> q; 
	q.push(12); 
	q.push(5); 
	q.push(15);
	q.push(20); 

	reverse(q); 
	Print(q); 
}

