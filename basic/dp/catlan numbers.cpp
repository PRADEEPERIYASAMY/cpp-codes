#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

// recursion
// https://www.geeksforgeeks.org/wp-content/ql-cache/quicklatex.com-6e37684751c57a980ebaca5148b4736a_l3.svg
// int catalan(int n){
//     if(n<= 1) return 1;
//     int res = 0;
//     for (int i = 0; i <n; i++) res+=catalan(i)*catalan(n-i-1); // ncr
//     return res;
// }

// dp
int catalan(int n){
    int dp[n+1];
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = 0;
        for (int j = 0; j < i; j++) {
            dp[i]+=(dp[j]*dp[i-j-1]);
        }
    }
    return dp[n];
}
 
int main() {
	for (int i = 0; i < 10; i++)
        cout << catalan(i) << " ";
    return 0;
}

