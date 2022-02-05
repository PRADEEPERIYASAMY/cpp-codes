#include <iostream>
using namespace std;

double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
    int n = quality.size();
    vector<pair<double,int>> vec;
    for (int i = 0; i < n; i++) vec.push_back({wage[i]*1.0/quality[i],quality[i]}); 
    sort(vec.begin(),vec.end(),[](auto &a,auto &b){return a.first<b.first;});
    int quality_count = 0;
    priority_queue<int> q;
    for (int i = 0; i < K; i++) {
        quality_count+=vec[i].second;
        q.push(vec[i].second);
    }
    double ans = quality_count*vec[K-1].first;
    for (int i = K; i < n; i++) {
        q.push(vec[i].second);
        quality_count+=vec[i].second;
        quality_count-=q.top();
        q.pop();
        ans = min(ans,quality_count *vec[i].first);
    }
    return ans;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/minimum-cost-to-hire-k-workers/discuss/142209/O(NlogN)-C%2B%2B-code-using-priority-queue-with-explanation
	return 0;
}

