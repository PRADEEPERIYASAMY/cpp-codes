using namespace std;
#include <bits/stdc++.h>
#define end "\n"
#define space " "

vector<int> twoSum(vector<int>& nums,int target){
    unordered_map<int,int> mp;
    for (int i = 0; i < nums.size(); i++) {
        if(mp.count(target-nums[i])) return vector<int>({mp[target-nums[i]],i});
        mp[nums[i]] = i;
    }
    return vector<int>({-1,-1});
}

int main(){
    //leet code solutions
    //https://jimmylin1991.gitbook.io/practice-of-algorithm-problems/array/1.-two-sum
    return 0;
}

