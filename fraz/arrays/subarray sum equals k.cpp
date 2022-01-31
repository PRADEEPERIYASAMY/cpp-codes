using namespace std;
#include <bits/stdc++.h>

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int,int> preSum;
    preSum[0]++;
    int sum = 0,res = 0;
    for (auto &i : nums) {
        sum+=i;
        if(preSum.count(sum-k)) res += preSum[sum-k];
        preSum[sum]++;
    }
    return res;
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/subarray-sum-equals-k/
    return 0;
}

