#include <bits/stdc++.h>
using namespace std;

// dp 
// int findLength(char *str){
//     int n = strlen(str);
//     int maxlen = 0;
//     int sum[n][n];
//     for (int i = 0; i < n; i++) sum[i][i] = str[i]-'0';
//     for (int len = 2; len <= n; len++) {
//         for (int i = 0; i < n - len +1; i++) {
//             int j = i+len - 1;
//             int k = len/2;
//             sum[i][j] = sum[i][j-k]+sum[j -k+1][j];
//             if(len%2 == 0 && sum[i][j-k] == sum[j-k+1][j] && len>maxlen) maxlen = len;
//         }
//     }
//     return maxlen;
// }

// space optimized method
int findLength(char *str){
    int n = strlen(str);
    int ans = 0;
    for (int i = 0; i <= n-2; i++) {
        int l = i,r = i+1;
        int lsum = 0,rsum = 0;
        while(r<n && l>= 0){
            lsum+=str[l]-'0';
            rsum+=str[r]-'0';
            if(lsum = rsum) ans = max(ans,r-l+1);
            l--;
            r++;
        }
    }
    return ans;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/longest-even-length-substring-sum-first-second-half/
	char str[] = "123123";
    cout << "Length of the substring is "<< findLength(str);
    return 0;
}
