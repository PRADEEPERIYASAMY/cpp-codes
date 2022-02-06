#include <iostream>
using namespace std;

int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    if(matrix.empty()) return 0;
    int row = matrix.size(),col = matrix[0].size(),res = INT_MIN;
    for (int l = 0; l < col; l++) {
        vector<int> sum(row,0);
        for (int r = l; r < col; r++) {
            for (int i = 0; i < row; i++) sum[i]+=matrix[i][r];
            set<int> accSet;
            accSet.insert(0);
            int curSum = 0,curMax = INT_MIN;
            for (auto s : sum) {
                curSum+=s;
                auto it = accSet.lower_bound(curSum-k);
                if(it!= accSet.end()) curMax = max(curMax,curSum - *it);
                accSet.insert(curSum);
            }
            res = max(res,curMax);
        }
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/discuss/83599/Accepted-C%2B%2B-codes-with-explanation-and-references
	return 0;
}

