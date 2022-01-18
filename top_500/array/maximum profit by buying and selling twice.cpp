using namespace std;
#include <bits/stdc++.h>

int maxProfit(int price[],int n){
    int profit[n] = {0};
    int max_price = price[n-1];
    for (int i = n-2; i >=0; i--) {
        max_price = max(max_price,price[i]);
        profit[i] = max(profit[i+1],max_price-price[i]);
    }
    int min_price = price[0];
    for (int i = 1; i < n; i++) {
        min_price = min(min_price,price[i]);
        profit[i] = max(profit[i-1],profit[i]+price[i]-min_price);
    }
    return profit[n-1];
}

int main(){
    int price[] = { 2, 30, 15, 10, 8, 25, 80 };
    int n = sizeof(price) / sizeof(price[0]);
    cout << "Maximum Profit = " << maxProfit(price, n);
    return 0;
}

