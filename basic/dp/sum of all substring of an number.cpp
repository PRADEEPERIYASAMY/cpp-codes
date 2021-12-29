#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

// dp
// (i+1)*num[i] + 10*sumofdigit[i-1]
int sumOfSubstrings(string num,int n){
    int dp[n];
    dp[0] = num[0]-'0';
    int res = dp[0];
    for (int i = 1; i < n; i++) {
        dp[i] = (i+1)*(num[i]-'0')+(10*dp[i-1]);
        res+=dp[i];
    }
    return res;
}

int main() {
    string num = "1234";
    cout << sumOfSubstrings(num,num.length()) << endl;
    return 0;
}

