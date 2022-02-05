#include <iostream>
using namespace std;

// dp 
// int minTaps(int n,vector<int> &A){
//     vector<int> dp(n+1,n+2);
//     dp[0] = 0;
//     for (int i = 0; i <=n; i++) {
//         for (int j = max(i-A[i],0); j<=min(i+A[i],n); j++) {
//             dp[j] = min(dp[j],dp[max(0,i-A[i])]+1);
//         }
//     }
//     return dp[n]< n+2?dp[n]:-1;
// }

// greedy approach
int minTaps(int n, vector<int>& ranges) {
    for (int i = 1; i < ranges.size(); i++) {
        if(ranges[i] == 0) ranges[i] = i;
        else {
            int range = max(0,i-ranges[i]);
            ranges[range] = max(i+ranges[i],ranges[range]);
        }
    }
    int maxIdx = 0;
    int pos = 0;
    int jump = 0;
    for (int i = 0; i < n; i++) {
        if(maxIdx<i) return -1;
        maxIdx = max(maxIdx,ranges[i]);
        if(i == pos){
            jump++;
            pos = maxIdx;
        }
    }
    return maxIdx>=n?jump:-1;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/discuss/927064/O(1)-Space-O(n)
	// https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/discuss/484235/JavaC%2B%2BPython-Similar-to-LC1024
	return 0;
}

