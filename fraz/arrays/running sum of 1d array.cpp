using namespace std;
#include <bits/stdc++.h>
#define end "\n"
#define space " "

vector<int> runningSum(vector<int> &nums){
    if(nums.size() == 1) return nums;
    for (int i = 1; i < nums.size(); i++) nums[i] += nums[i-1];
    return nums;
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/running-sum-of-1d-array/
    return 0;
}

