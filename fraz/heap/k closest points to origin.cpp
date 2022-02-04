#include <iostream>
using namespace std;

// Naive sorting nlog(n)
// vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
//     vector<vector<int>> res;
//     sort(points.begin(),points.end(),[](const vector<int> &a,const vector<int> &b){
//         return a[0]*a[0]+a[1]*a[1]<b[0]*b[0]+b[1]*b[1];
//     });
//     res = vector<vector<int>>(points.begin(),points.begin()+K);
//     return res;
// }

// Max heap nlog(k)
// vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
//     vector<vector<int>> res;
//     if(points.empty() || K == 0) return res;
//     auto comp = [](const vector<int> &a,const vector<int> &b){
//         return a[0]*a[0]+a[1]*a[1]<b[0]*b[0]+b[1]*b[1];
//     };
//     priority_queue<vector<int>,vector<vector<int>>,decltype(comp)> pq(comp);
//     for (auto &i : points) {
//         pq.push(i);
//         if(pq.size()>K) pq.pop();
//     }
//     while(!pq.empty()){
//         res.push_back(pq.top());
//         pq.pop();
//     }
//     return res;
// }

int compare(vector<int> &a,vector<int> &b){
    return (a[0] * a[0] + a[1] * a[1]) - (b[0] * b[0] + b[1] * b[1]);
}

int partition(vector<vector<int>> &points,int left,int right){
    vector<int> pivot = points[right];
    int p_idx = left;
    for (int i = left; i < right; i++) if(compare(points[i],pivot)<=0) swap(points[i],points[p_idx++]);
    swap(points[p_idx],points[right]);
    return p_idx;
}

vector<vector<int>> kClosest(vector<vector<int>>& points, int K) { // time: average O(n), worst O(n^2); space: O(K)
    int left = 0,right = points.size()-1;
    while(left<=right){
        int mid = partition(points,left,right);
        if(mid == K) break;
        if(mid<K) left = mid+1;
        else right = mid-1;
    }
    return vector<vector<int>> (points.begin(),points.begin()+K);
}

int main() {
	// leetcode
	// https://leetcode.com/problems/k-closest-points-to-origin/
	return 0;
}

