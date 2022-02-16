#include <iostream>
using namespace std;

int removeBoxes(vector<int>& boxes) {
    if(boxes.empty()) return 0;
    int n = boxes.size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(n,0)));
    for (int i = 0; i < n; i++) for (int k = 0; k <= i; k++) dp[i][i][k] = (1+k)*(1+k);
    for (int l = 1; l < n; l++) {
        for (int j = l; j < n; j++) {
            int i = j - l;
            for (int k = 0; k <= i; k++) {
                int res = (1+k)*(1+k)+dp[i+1][j][0];
                for (int m = i+1; m <= j; m++) {
                    if(boxes[m] == boxes[i]) res = max(res,dp[i+1][m-1][0]+dp[m][j][k+1]);
                }
                dp[i][j][k] = res;
            }
        }
    }
    return dp[0][n-1][0];
}

int main() {
	// leetcode
	// https://leetcode.com/problems/remove-boxes/
	// https://leetcode.com/problems/remove-boxes/discuss/1402561/C%2B%2BJavaPython-Top-down-DP-Clear-explanation-with-Picture-Clean-and-Concise
	return 0;
}

