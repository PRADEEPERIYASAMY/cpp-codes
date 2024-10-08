#include <iostream>
using namespace std;

int furthestBuilding(vector<int>& A, int bricks, int ladders) {
    priority_queue<int> pq;
    for (int i = 0; i < A.size()-1; i++) {
        int d = A[i+1]-A[i];
        if(d>0) pq.push(-d);
        if(pq.size()>ladders){
            bricks+=pq.top();
            pq.pop();
        }
        if(bricks<0) return i;
    }
    return A.size()-1;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/furthest-building-you-can-reach/discuss/918515/JavaC%2B%2BPython-Priority-Queue
	return 0;
}

