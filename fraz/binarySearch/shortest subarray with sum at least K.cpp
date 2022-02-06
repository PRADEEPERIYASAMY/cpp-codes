#include <iostream>
using namespace std;

// O(nlogn) Min Heap
// int shortestSubarray(vector<int>& A, int K) {
//     int n = A.size(),res = INT_MAX,sum = 0;
//     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
//     for (int i = 0; i < n; i++) {
//         sum+=A[i];
//         if(sum>=K) res = min(res,i+1);
//         while(!pq.empty() && sum - pq.top().first>=K){
//             res = min(res,i - pq.top().second);
//             pq.pop();
//         }
//         pq.push({sum,i});
//     }
//     return res == INT_MAX?-1:res;
// }

// O(n) Deque Solution
int shortestSubarray(vector<int>& A, int K) {
    int n = A.size(),res = INT_MAX;
    deque<int> dq;
    vector<long long> sums(n+1);
    for (int i = 1; i <= n; i++) sums[i] = sums[i-1]+A[i-1];
    for (int i = 0; i <= n; i++) {
        while(!dq.empty() && sums[i] - sums[dq.front()]>=K){
            res = min(res,i - dq.front());
            dq.pop_front();
        }
        while(!dq.empty() && sums[i]<= sums[dq.back()]) dq.pop_back();
        dq.push_back(i);
    }
    return res == INT_MAX?-1:res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/split-array-largest-sum/
	return 0;
}

