#include <iostream>
using namespace std;

string getPermutation(int n, int k) {
    string res ;
    string nums = "123456789";
    vector<int> factorial(n,1);
    for (int i = 1; i < n; i++) factorial[i] = factorial[i-1]*i;
    k--;
    for (int i = n; i >= 1; i--) {
        int j = k/factorial[i-1];
        k%=factorial[i-1];
        res.push_back(nums[j]);
        nums.erase(nums.begin()+j);
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/permutation-sequence/
	return 0;
}

