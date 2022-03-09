#include <bits/stdc++.h>
using namespace std;

// recursive
// unordered_set<string> mp;
// void subsequences(char s[],char op[],int i,int j){
//     if(s[i] == '\0'){
//         op[j] = '\0';
//         mp.insert(op);
//         return;
//     }else{
//         op[j] = s[i];
//         subsequences(s,op,i+1,j+1);
//         subsequences(s,op,i+1,j);
//         return;
//     }
// }

// dp
const int MAX_CHAR = 256;
int countSub(string str){
    vector<int> last(MAX_CHAR,-1);
    int n = str.size();
    int dp[n+1];
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = 2*dp[i-1];
        if(last[str[i-1]] != -1) dp[i] -= dp[last[str[i-1]]];
        last[str[i-1]] = i-1;
    }
    return dp[n];
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/count-distinct-subsequences/
// 	char str[] = "ggg";
//     int m = sizeof(str) / sizeof(char);
//     char op[m+1]; //extra one for having \0 at the end
//     subsequences(str, op, 0, 0);
//     cout << mp.size();
//     mp.clear();
    cout << countSub("gfg");
    return 0;
}
