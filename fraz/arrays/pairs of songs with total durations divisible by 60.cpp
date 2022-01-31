using namespace std;
#include <bits/stdc++.h>

int numPairsDivisibleBy60(vector<int>& time) {
    int map[60] = {0};
    int result = 0;
    for (auto &x : time) {
        int t = x%60;
        int y = (60 - t)%60;
        result += map[y];
        map[t]++;
    }
    return result;
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/
    return 0;
}

