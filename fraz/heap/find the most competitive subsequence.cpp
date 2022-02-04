#include <iostream>
using namespace std;

vector<int> mostCompetitive(vector<int>& nums, int k) {
    vector<int> stack;
    int numsToBedeletd = nums.size()-k;
    for (int i = 0; i < nums.size(); i++) {
        while(!stack.empty() && nums[i]<stack.back() && numsToBedeletd){
            stack.pop_back();
            numsToBedeletd--;
        }
        stack.push_back(nums[i]);
    }
    return vector<int>(stack.begin(),stack.begin()+k);
}

int main() {
	// leetcode
	// https://leetcode.com/problems/find-the-most-competitive-subsequence/discuss/1027527/C%2B%2BSimple-and-Short-Solution-faster-than-100
	return 0;
}

