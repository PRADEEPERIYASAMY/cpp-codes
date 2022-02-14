#include <iostream>
using namespace std;

int maxProfit(vector<int> &prices){
    int res = 0;
    for (int i = 1; i < prices.size(); i++) res +=max(0,prices[i] - prices[i-1]);
    return res;
}

// DP + Greedy
int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    if(n<= 1) return 0;
    else if(k>=n/2) return maxProfit(prices);
    else {
        vector<int> sell(k+1,0),buy(k+1,INT_MIN);
        for (int i = 0; i < n; i++) {
            for (int j = k; j >= 1; j--) {
                sell[j] = max(sell[j],buy[j]+prices[i]);
                buy[j] = max(buy[j],sell[j-1] - prices[i]);
            }
        }
        return sell[k];
    }
}

int main() {
	// leetcode
	// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
	return 0;
}

