#include <bits/stdc++.h>
using namespace std;

//dp 
// int maxProfit(vector<int>& prices) {
//     int n = prices.size();
//     if(n<=1) return 0;
//     vector<int> buy(n,INT_MIN),sell(n,0);
//     for (int i = 0; i < n; i++) {
//         buy[i] = max((i>=1?buy[i-1]:INT_MIN),(i>=2?sell[i-2]:0)-prices[i]);
//         sell[i] = max((i>=1?sell[i-1]:0),(i>=1?buy[i-1]+prices[i]:0));
//     }
//     return sell.back();
// }
int maxProfit(vector<int> &prices){
    int preBuy = INT_MIN,buy = INT_MIN,preSell = 0,sell = 0;
    for (auto &price : prices) {
        preBuy = buy;
        buy = max(buy,preSell - price);
        preSell = sell;
        sell = max(sell,preBuy+price);
    }
    return sell;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
    return 0;
}
