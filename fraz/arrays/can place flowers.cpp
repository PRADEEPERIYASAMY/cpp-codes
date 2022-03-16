#include <bits/stdc++.h>
using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    if(flowerbed.empty()) return false;
    if(n == 0) return true;
    int cnt = 0,i = 0;
    while(i< flowerbed.size()){
        if(flowerbed[i] == 1) i+=2;
        else if((i == 0 || flowerbed[i-1] == 0) && (i == flowerbed.size()-1 || flowerbed[i+1] == 0)){
            if(++cnt == n) return true;
            i+=2;
        }else i++;
    }
    return false;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/can-place-flowers/
    return 0;
}
