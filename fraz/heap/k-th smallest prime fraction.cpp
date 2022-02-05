#include <iostream>
using namespace std;

vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
    priority_queue<pair<double,pair<int,int>>> pq;
    for (int i = 0; i < A.size(); i++) pq.push({-1.0*A[i]/A.back(),{i,A.size()-1}});
    while(--K){
        auto[ratio,index] = pq.top();
        pq.pop();
        index.second--;
        pq.push({-1.0*A[index.first]/A[index.second],{index.first,index.second}});
    }
    return {A[pq.top().second.first],A[pq.top().second.second]};
}

int main() {
	// leetcode
	// https://leetcode.com/problems/k-th-smallest-prime-fraction/discuss/115531/C%2B%2B-9lines-priority-queue
	return 0;
}

