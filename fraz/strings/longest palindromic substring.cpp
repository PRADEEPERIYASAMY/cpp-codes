#include <iostream>
using namespace std;

// void helper(string &s,int l,int r,int &start,int &max_len){
//     while(l>=0 && r<s.size() && s[l] == s[r]) l--,r++;
//     if(max_len<r-l-1){
//         max_len = r-l-1;
//         start = l+1;
//     }
//     return;
// }

// // expand from the center
// string longestPalindrome(string s) {
//     int n = s.size(),start = 0,max_len = 0;
//     if(n<2) return s;
//     for (int i = 0; i < n; i++) {
//         helper(s,i,i,start,max_len); // odd length
//         helper(s,i,i+1,start,max_len); // even length
//     }
//     return s.substr(start,max_len);
// }

// dp 
string longestPalindrome(string s) {
    int n = s.size(),start = 0,max_len = 1;
    vector<vector<bool>> dp(n,vector<bool>(n,false));
    for (int j = 0; j < n; j++) {
        dp[j][j] = true;
        for (int i = j-1; i >=0 ; i--) {
            dp[i][j] = (s[i] == s[j]) && (j-i < 2 || dp[i+1][j-1] );
            if(dp[i][j] && j-i+1 > max_len){
                start = i;
                max_len = j-i+1;
            }
        }
    }
    return s.substr(start,max_len);
}

int main() {
	// leetcode
	// https://leetcode.com/problems/longest-palindromic-substring/
	return 0;
}

