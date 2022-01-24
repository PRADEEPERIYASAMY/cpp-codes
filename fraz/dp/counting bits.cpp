using namespace std;
#include <bits/stdc++.h>
#define end "\n"
#define space " "

vector<int> countBits(int num) {
    vector<int> dp(num+1,0);
    for (int i = 1; i <= num; i++) dp[i] = dp[i>>1]+(i&1);
    return dp;
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/counting-bits/
    return 0;
}

