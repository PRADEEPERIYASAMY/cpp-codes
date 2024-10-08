#include <bits/stdc++.h>
using namespace std;

int josephusCircle(int n,int k){
    list<int> l;
    for (int i = 0; i < n; i++) l.push_back(i);
    auto it = l.begin();
    while(l.size()>1){
        for (int i = 1; i < k; i++) {
            it++;
            if(it == l.end()) it = l.begin();
        }
        it = l.erase(it);
        if(it == l.end()) it = l.begin();
    }
    return l.front();
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/josephus-circle-using-circular-linked-list/
	int n=14,k=2;
    cout<<josephusCircle(n,k)<<"\n";
    return 0;
}
