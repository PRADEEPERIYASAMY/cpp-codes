using namespace std;
#include <bits/stdc++.h>
#define end "\n"
#define space " "

int maxProfit(vector<int> &prices){
    int res = 0,buy = INT_MAX;
    for (auto &i : prices) {
        buy = min(buy,i);
        res = max(res,i-buy);
    }
    return res;
}

int main(){
    //leet code solutions
    //https://jimmylin1991.gitbook.io/practice-of-algorithm-problems/array/121.-best-time-to-buy-and-sell-stock
    return 0;
}

