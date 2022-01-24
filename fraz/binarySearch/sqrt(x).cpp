using namespace std;
#include <bits/stdc++.h>

// int mySqrt(int x){
//     if(x<=1) return x;
//     int l = 0,r = x;
//     while(l<r){
//         int mid = l+(r-l)/2;
//         if(mid <= x/mid) l = mid+1;
//         else r = mid;
//     }
//     return r-1;
// }

// newtons method
int mySqrt(int x){
    if(x<=1) return x;
    int r = x/2;
    while(r>x/r) r = (r+x/r)/2;
    return r;
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/sqrtx/
    return 0;
}

