#include <bits/stdc++.h> 
using namespace std; 

void printFirstN(int n){
    queue<string> q;
    q.push("5");q.push("6");
    for (int i = 0; i < n; i++) {
        string cur = q.front();
        cout<<cur<<" ";
        q.pop();
        q.push(cur+"5");q.push(cur+"6");
    }
}

int main() {
	int n = 5;
	printFirstN(n);
	return 0;
}

