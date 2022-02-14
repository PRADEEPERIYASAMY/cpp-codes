#include <iostream>
using namespace std;

// Dynamic programming
// int trap(vector<int>& height) {
//     int res = 0,mx = 0,n = height.size();
//     vector<int> dp(n,0);
//     for (int i = 0; i < n; i++) {
//         dp[i] = mx;
//         mx = max(mx,height[i]);
//     }
//     mx = 0;
//     for (int i = n-1; i >= 0; i--) {
//         dp[i] = min(dp[i],mx);
//         mx = max(mx,height[i]);
//         if(dp[i]>height[i]) res+=dp[i] - height[i];
//     }
//     return res;
// }

// Two pointers
// int trap(vector<int>& height) { 
//     int n = height.size(),l = 0,r = n-1,maxL = 0,maxR = 0,res = 0;
//     while(l<r){
//         if(height[l]<=height[r]){
//             if(height[l]>maxL) maxL = height[l];
//             else res+=maxL - height[l];
//             l++;
//         }else{
//             if(height[r]>= maxR) maxR = height[r];
//             else res+=maxR - height[r];
//             r--;
//         }
//     }
//     return res;
// }

// Monotonic Stack
int trap(vector<int>& height) {
    int res = 0,i = 0,n = height.size();
    stack<int> st;
    while(i<n){
        if(st.empty() || height[i]<height[st.top()]) st.push(i++);
        else{
            int t = st.top();st.pop();
            if(st.empty()) continue;
            res+=(min(height[st.top()],height[i]) - height[t])*(i - st.top() - 1);
        }
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/trapping-rain-water/
	return 0;
}

