#include <bits/stdc++.h>
using namespace std;

// recursive
// int countSol(int coeff[],int start,int end,int rhs){
//     if(rhs == 0) return 1;
//     int result = 0;
//     for (int i = start; i <= end; i++) {
//         if(coeff[i]<=rhs) result+=countSol(coeff,i,end,rhs - coeff[i]);
//     }
//     return result;
// }

// dp 
int countSol(int coeff[],int n,int rhs){
    int dp[rhs+1];
    fill(dp,dp+rhs+1,0);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = coeff[i]; j <= rhs; j++) {
            dp[j] +=dp[j - coeff[i]];
        }
    }
    return dp[rhs];
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/find-number-of-solutions-of-a-linear-equation-of-n-variables/
	int coeff[] = {2, 2, 5};
    int rhs = 4;
    int n = sizeof(coeff) / sizeof(coeff[0]);
    //cout << countSol(coeff, 0, n - 1, rhs);
    cout<<countSol(coeff,n,rhs);
    return 0;
}
