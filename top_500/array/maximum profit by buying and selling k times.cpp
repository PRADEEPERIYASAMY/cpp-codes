using namespace std;
#include <bits/stdc++.h>

int maxProfit(int price[],int n,int k){
    int profit[k+1][n+1];
    for (int i = 0; i <= k; i++) profit[i][0] = 0;
    for (int i = 0; i <= n; i++) profit[0][i] = 0;
    for (int i = 1; i <= k; i++) {
        int pervDiff = INT_MIN;
        for (int j = 1; j <n; j++) {
            pervDiff = max(pervDiff,profit[i-1][j-1]-price[j-1]);
            profit[i][j] = max(profit[i][j-1],price[j]+pervDiff);
        }
    }
    return profit[k][n-1];
}

int main(){
    int k = 3;
    int price[] = { 12, 14, 17, 10, 14, 13, 12, 15 };
    int n = sizeof(price) / sizeof(price[0]);
    cout << "Maximum profit is: "<< maxProfit(price, n, k);
    return 0;
}

