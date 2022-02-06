#include <iostream>
using namespace std;

// binary search
// bool canSplit(int target,vector<int>& nums,int m){
//     int cnt = 1;
//     long long curSum = 0;
//     for (int i = 0; i < nums.size(); i++) {
//         curSum+=nums[i];
//         if(curSum>target){
//             curSum = nums[i];
//             cnt++;
//             if(cnt>m) return false;
//         }
//     }
//     return true;
// }

// int splitArray(vector<int>& nums, int m) {
//     long long left = 0,right = 0;
//     for (auto &num : nums) {
//         left = max(left,(long long) num);
//         right +=num;
//     }
//     if(m == 1) return (int) right;
//     while(left<right){
//         long long mid = left+(right - left)/2;
//         if(canSplit(mid,nums,m)) right = mid;
//         else left = mid+1;
//     }
//     return (int) left;
// }

// dynamic programming
int splitArray(vector<int> &nums,int m){
    int n = nums.size();
    vector<long> sums(n+1,0);
    vector<vector<int>> dp(m+1,vector<int>(n+1,INT_MAX));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) sums[i] = sums[i-1]+nums[i-1];
    for (int i = 1; i <= m; i++) { // i subarrays
        for (int j = 1; j <= n; j++) { // first j numbers in nums array
            for (int k = i-1; k< j; k++) { // the kth number in nums array
                int val = max(dp[i-1][k],(int)(sums[j]-sums[k]));
                dp[i][j] = min(dp[i][j],val);
            }
        }
    }
    return dp[m][n];
}

int main() {
	// leetcode
	// https://leetcode.com/problems/split-array-largest-sum/
	return 0;
}


