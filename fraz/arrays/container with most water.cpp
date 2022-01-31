using namespace std;
#include <bits/stdc++.h>

int maxArea(vector<int>& height) {
    int res = 0,n = height.size(),l = 0,r = n-1;
    while(l<r) {
        res = max(res,min(height[l],height[r])*(r-l));
        if(height[l]<=height[r]) l++;
        else r--;
    }
    return res;
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/container-with-most-water/
    return 0;
}

