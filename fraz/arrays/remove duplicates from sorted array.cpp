using namespace std;
#include <bits/stdc++.h>
#define end "\n"
#define space " "

int removeDuplicates(vector<int>& nums){
    if(nums.empty()) return 0;
    int ind = 1;
    for (int i = 1; i < nums.size(); i++) if(nums[i]!=nums[i-1])nums[ind++] = nums[i];
    return ind;
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/remove-duplicates-from-sorted-array/
    return 0;
}

