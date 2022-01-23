using namespace std;
#include <bits/stdc++.h>
#define end "\n"
#define space " "

int maxProfit(vector<int> &prices){
    int res = 0;
    for (int i = 1; i < prices.size(); i++) if(prices[i]- prices[i-1]>0) res+=(prices[i]- prices[i-1]);
    return res;
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
    return 0;
}

