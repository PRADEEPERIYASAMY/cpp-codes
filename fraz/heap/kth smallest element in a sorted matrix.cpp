#include <iostream>
using namespace std;

// Priority queue
// int kthSmallest(vector<vector<int>>& matrix, int k) {
//     auto cmp = [](const vector<int> &a,const vector<int> &b){
//         return a[2]>b[2];
//     };
//     priority_queue<vector<int>,vector<vector<int>>,decltype(cmp)> pq(cmp);
//     for (int i = 0; i < matrix[0].size(); i++) pq.push({0,i,matrix[0][i]});
//     for (int i = 0; i < k-1; i++) {
//         vector<int> t = pq.top();pq.pop();
//         if(t[0] == matrix.size()-1) continue;
//         int row_idx = t[0]+1;
//         pq.push({row_idx,t[1],matrix[row_idx][t[1]]});
//     }
//     return pq.top()[2];
// }

// Binary Search
int kthSmallest(vector<vector<int>>& matrix, int k) {
    int l = matrix.front().front(),r = matrix.back().back();
    while(l<r){
        int mid = l+(r-l)/2,count = 0,j = matrix[0].size()-1;
        for (int i = 0; i < matrix.size(); i++) {
            while(j>=0 && matrix[i][j]>mid) j--;
            count+=(j+1);
        }
        if(count<k) l = mid+1;
        else r = mid;
    }
    return r;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
	return 0;
}

