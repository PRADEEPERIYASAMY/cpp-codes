#include<bits/stdc++.h>
using namespace std;

// dp tabularation
// int countFriendsPairings(int n){
//     int dp[n+1];
//     for (int i = 0; i <= n; i++) {
//         if(i<=2) dp[i] = i;
//         else dp[i] = dp[i-1]+(i-1)*dp[i-2]; // two options for nth person 
//     }
//     return dp[n];
// }

// dp memorization
// int dp[1000];
// int countFriendsPairings(int n){
//     if(dp[n] != -1) return dp[n];
//     if(n>2) return dp[n] = countFriendsPairings(n-1)+(n-1)*countFriendsPairings(n-2);
//     else return dp[n] = n;
// }

// using fib
int countFriendsPairings(int n){
    int a = 1,b = 2,c = 0;
    if(n<=2) return n;
    for (int i = 3; i <= n; i++) {
        c = b+(i-1)*a;
        a = b;
        b = c;
    }
    return c;
}

int main() {
    //memset(dp,-1,sizeof(dp));
    int n = 4;
    cout << countFriendsPairings(n) << endl;
    return 0;
}

