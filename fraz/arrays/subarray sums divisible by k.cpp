#include <iostream>
using namespace std;

// we find subarray sum from from i to j by 
// SUM[i-1] - SUM[j]
// if it has to be div by K then 
// SUM[i-1] - SUM[j] = K*something
// OR (SUM[i-1] - SUM[j]) %K  = (K*something) %K = 0
// OR SUM[i-1] % k == SUM[j]%k
// So basically for any SUM[i] if its remainder is same as remainder of any other SUM[ some index] then their sum % k == 0

int subarraysDivByK(vector<int>& A, int K) {
    unordered_map<int,int> preMod;
    preMod[0] = 1;
    int res = 0,sum = 0;
    for (auto &i : A) {
        sum = (((sum+i)%K)+K)%K; // +k because of negative num
        res+=preMod[sum]++;
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/subarray-sums-divisible-by-k/
	return 0;
}

