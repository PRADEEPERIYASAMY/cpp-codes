#include <bits/stdc++.h>
using namespace std;

// naive
//unordered_set<string> sn;
// void subsequence(string str,string op,int i){
//     if(i == str.size()){
//         sn.insert(op);
//         return;
//     }
//     subsequence(str,op,i+1);
//     op.push_back(str[i]);
//     subsequence(str,op,i+1);
// }

const int MAX_CHAR = 256;
int countSub(string str){
    vector<int> last(MAX_CHAR,-1);
    int n = str.size();
    int dp[n+1];
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = 2*dp[i-1];
        if(last[str[i-1]]!=-1) dp[i]-=dp[last[str[i-1]]];
        last[str[i-1]] = i-1;
    }
    return dp[n];
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/count-distinct-subsequences/
// 	string str = "ggg";
// 	int m = str.size();
// 	int n = pow(2,m)+1;
// 	string op;
// 	subsequence(str,op,0);
// 	cout<<sn.size();
// 	sn.clear();
    cout << countSub("gfg");
    return 0;
}

