using namespace std;
#include <bits/stdc++.h>
#define end "\n"
#define space " "

bool divisorGame(int N) {
    vector<bool> dp(N+1,false);
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            if(i%j == 0) if(!dp[i-j]){
                dp[i] = true;
                break;
            }
        }
    }
    return dp[N];
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/divisor-game/
    return 0;
}

