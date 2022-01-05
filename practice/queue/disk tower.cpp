#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin>>n;
    int counter = n;
    int num;
    priority_queue<int> pq;
    while(n--){
        cin>>num;
        pq.push(num);
        while(pq.top() == counter){
            cout<<pq.top()<<" ";
            pq.pop();
            counter--;
        }
        cout<<endl;
    }
    
	return 0;
}

