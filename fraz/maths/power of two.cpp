using namespace std;
#include <bits/stdc++.h>
#define end "\n"
#define space " "

bool isPowerOfTwo(int n) {
    if(n<=0) return false;
    return ((n&(n-1)) == 0);
}

// bool isPowerOfTwo(int n){
//     if(n<=0) return false;
//     return ceil(log2(n)) == floor(log2(n));
// }

// bool isPowerOfTwo(int n){
//     if(n == 0) return false;
//     while(n%2==0) n/=2;
//     return n==1;
// }

// bool isPowerOfTwo(int n){
//     if(n == 0) return false;
//     return n == 1 || (n%2 == 0 && isPowerOfTwo(n/2));
// }

int main(){
    //leet code solutions
    //https://leetcode.com/problems/power-of-two/
    return 0;
}

