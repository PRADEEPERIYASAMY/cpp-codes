#include <bits/stdc++.h>
using namespace std;

int sum(int freq[],int i,int j){
    int s = 0;
    for (int k = i; k <= j; k++) s+=freq[k];
    return s;
}
//recursive
//https://www.geeksforgeeks.org/wp-content/ql-cache/quicklatex.com-e4743c2643482de74b0d72a870910016_l3.svg
// int optCost(int freq[],int i,int j){
//     if(j<i) return 0;
//     if(j == i) return freq[i];
//     int fsum = sum(freq,i,j);
//     int m = INT_MAX;
//     for (int r = i; r <= j; r++) {
//         int cost = optCost(freq,i,r-1)+optCost(freq,r+1,j);
//         m = min(m,cost);
//     }
//     return m+fsum;
// }

// int optimalSearchTree(int keys[],int freq[], int n){
//     return optCost(freq,0,n-1);
// }

// dp
int optimalSearchTree(int keys[],int freq[],int n){
    int dp[n][n];
    for (int i = 0; i <n; i++) dp[i][i] = freq[i];
    for (int gap = 2; gap <= n; gap++) {
        for (int i = 0; i <= n-gap+1; i++) {
            int j = i+gap-1;
            dp[i][j] = INT_MAX;
            for (int r = i; r <= j; r++) {
                int cost = ((r > i)? dp[i][r-1]:0) +((r < j)? dp[r+1][j]:0) +sum(freq, i, j);
                dp[i][j] = min(dp[i][j],cost);
            }
        }
    }
    return dp[0][n-1];
}

int main(){
    int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    int n = sizeof(keys) / sizeof(keys[0]);
    cout << "Cost of Optimal BST is "<< optimalSearchTree(keys, freq, n);
    return 0;
}

