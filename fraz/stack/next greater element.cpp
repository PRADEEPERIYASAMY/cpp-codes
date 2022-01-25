using namespace std;
#include <bits/stdc++.h>

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res;
    unordered_map<int,int> mp;
    stack<int> st;
    for (auto &i : nums2) {
        while(!st.empty() && st.top() <i){
            mp[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    for (auto &i : nums1) {
        res.push_back(mp.count(i)?mp[i]:-1);
    }
    return res;
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/next-greater-element-i/
    return 0;
}

