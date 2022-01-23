using namespace std;
#include <bits/stdc++.h>
#define end "\n"
#define space " "

int pivotIndex(vector<int> &nums){
    int sum = accumulate(nums.begin(),nums.end(),0);
    int leftSum = 0;
    for (int i = 0; i < nums.size(); i++) {
        if(leftSum == sum-nums[i]) return i;
        leftSum+=nums[i];
        sum-=nums[i];
    }
    return -1;
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/find-pivot-index/
    return 0;
}

