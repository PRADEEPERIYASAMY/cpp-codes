#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    int n = nums.size(),cand1 = 0,cand2 = 0,cnt1 = 0,cnt2 = 0;
    vector<int> res;
    for (auto &num : nums) {
        if(num == cand1) cnt1++;
        else if(num == cand2) cnt2++;
        else if(cnt1 == 0){
            cand1 = num;
            cnt1++;
        }else if(cnt2 == 0){
            cand2 = num;
            cnt2++;
        }else cnt1--,cnt2--;
    }
    cnt1 = 0,cnt2 = 0;
    for (auto &num : nums) {
        if(num == cand1) cnt1++;
        else if(num == cand2) cnt2++;
    }
    if(cnt1>n/3) res.push_back(cand1);
    if(cnt2>n/3) res.push_back(cand2);
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/summary-ranges/
    return 0;
}
