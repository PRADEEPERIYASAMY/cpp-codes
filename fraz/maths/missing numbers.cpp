using namespace std;
#include <bits/stdc++.h>
#define end "\n"
#define space " "

// int missingNumber(vector<int>& nums) {
//     int res = 0;
//     for (int i = 0; i < nums.size(); i++) res^=(i+1)^nums[i];
//     return res;
// }

int missingNumber(vector<int> &nums){
    int n = nums.size();
    int sum = accumulate(nums.begin(),nums.end(),0);
    return (n*(n+1)/2)-sum;
    
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/missing-number/
    return 0;
}

