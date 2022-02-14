#include <iostream>
using namespace std;

int maxQuerry(vector<int> &arr,int i,int j){
    return *max_element(arr.begin()+i,arr.begin()+j+1);
}

int minDifficulty(vector<int>& arr, int day) {
    int n = arr.size();
    vector<vector<int>> dp(12,vector<int>(305,1e6));
    if(n<day) return -1;
    for (int i = 0; i < n; i++) dp[1][i] = maxQuerry(arr,i,n-1);
    for (int d = 2; d <= day ; d++) {
        for (int i = 0; i < n; i++) {
            if(n-i<d) { // too many days left
                dp[d][i] = 1e6;
                continue;
            }
            for (int j = i; j < n; j++) {
                dp[d][i] = min(dp[d][i],maxQuerry(arr,i,j)+dp[d-1][j+1]);
            }
        }
    }
    return dp[day][0];
}

int main() {
	// leetcode
	// https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/discuss/490256/C%2B%2B-DP-solution-with-explanation
	return 0;
}

