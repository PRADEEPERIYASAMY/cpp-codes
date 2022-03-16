#include <bits/stdc++.h>
using namespace std;

int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    int res = 0,n = timeSeries.size(),end = 0;
    for (int i = 0; i < n; i++) {
        if(i != n-1){
            end = timeSeries[i]+(duration-1);
            if(end < timeSeries[i+1]) res+=duration;
            else res +=(timeSeries[i+1] - timeSeries[i]);
        }else res+=duration;
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/teemo-attacking/
    return 0;
}
