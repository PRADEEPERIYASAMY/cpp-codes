using namespace std;
#include <bits/stdc++.h>
#define end "\n"
#define space " "

void moveZeroes(vector<int> &nums){
    int ind = 0;
    for (int i = 0; i < nums.size(); i++) if(nums[i]!=0) swap(nums[i],nums[ind++]);
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/move-zeroes/
    return 0;
}

