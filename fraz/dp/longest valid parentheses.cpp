#include <iostream>
using namespace std;

// Dynamic programming
// int longestValidParentheses(string s) {
//     int n = s.size(),res = 0;
//     if(n<= 1) return res;
//     vector<int> dp(n,0);
//     for (int i = 1; i < n; i++) {
//         if(s[i] == '(') continue;
//         if(s[i] == ')'){
//             if(s[i-1] == ')'){
//                 if(i - 1 - dp[i-1]>= 0 && s[i - 1 - dp[i-1]] == '('){
//                     dp[i] = dp[i-1]+2+((i-dp[i-1] - 2)>= 0? dp[i - dp[i -1] - 2]:0);
//                 }
//             }else{
//                 dp[i] = (i>=2?dp[i-2]:0)+2;
//             }
//         }
//         res = max(res,dp[i]);
//     }
//     return res;
// }

// Stack
int longestValidParentheses(string s) {
    int n = s.size(),res = 0;
    if(n<= 1) return res;
    int start = 0;
    stack<int> st;
    for (int i = 0; i < n; i++) {
        if(s[i] == '(') st.push(i);
        else{
            if(st.empty()) start = i+1;
            else{
                st.pop();
                res = max(res,(st.empty()?i-start+1:i-st.top()));
            }
        }
    }
    return res;
 }

int main() {
	// leetcode
	// https://leetcode.com/problems/longest-valid-parentheses/
	return 0;
}

