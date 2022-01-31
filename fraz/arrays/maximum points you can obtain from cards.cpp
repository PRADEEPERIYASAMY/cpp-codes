#include <iostream>
using namespace std;

int maxScore(vector<int>& cardPoints, int k) {
    int sum = 0;
    int n = cardPoints.size();
    int lsum = 0,rsum = 0;
    for (int i = 0; i < k; i++) lsum+=cardPoints[i];
    int res = lsum;
    for (int i = 0; i < k; i++){
        rsum +=cardPoints[n-i-1];
        lsum -=cardPoints[k-i-1];
        res = max(res,lsum+rsum);
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/discuss/597825/Simple-Clean-Intuitive-Explanation-with-Visualization
	// in the comment section of the post the answer will be there
	return 0;
}

