#include <iostream>
using namespace std;

// int maxProfit(vector<int>& prices) {
//     int sell1 = 0,sell2 = 0,buy1 = INT_MIN,buy2 = INT_MIN;
//     for (auto &price : prices) {
//         buy1 = max(buy1,-price);
//         sell1 = max(sell1,price+buy1);
//         buy2 = max(buy2,sell1 - price);
//         sell2 = max(sell2,price+buy2);
//     }
//     return sell2;
// }


// dp 
int maxProfit(vector<int> &prices){
    vector<int> buy(3,INT_MIN),sell(3,0);
    for (int i = 0; i < prices.size(); i++) {
        for (int j = 2; j>= 1; j--) {
            sell[j] = max(sell[j],buy[j]+prices[i]);
            buy[j] = max(buy[j],sell[j-1]-prices[i]);
        }
    }
    return sell[2];
}

int main() {
	// leetcode
	// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
	return 0;
}

