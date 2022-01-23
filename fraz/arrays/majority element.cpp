using namespace std;
#include <bits/stdc++.h>
#define end "\n"
#define space " "

int majorityElement(vector<int>& nums){
    int res = 0,count = 0;
    for (int i = 0; i < nums.size(); i++) {
        if(count == 0){
            res = nums[i];
            count++;
        }else nums[i] == res?count++:count--;
    }
    return res;
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/majority-element/
    return 0;
}

