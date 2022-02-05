#include <iostream>
using namespace std;

// not working for few cases
// int divide(int dividend, int divisor) {
//     if(dividend == 0) return 0;
//     if(divisor == 0|| (dividend == INT_MIN && divisor == -1)) return INT_MAX;
//     long double ln_m = log(fabs(dividend)),ln_n = log(fabs(divisor));
//     long long res = double(exp(ln_m-ln_n));
//     return (dividend>0)^(divisor>0)? -res:res;
// }

// Bit Manipulation
int divide(int dividend, int divisor) {
    if(dividend == 0) return 0;
    if(divisor == 0|| (dividend == INT_MIN && divisor == -1)) return INT_MAX;
    int sign = (dividend>0)^(divisor>0)?-1:1;
    long m = labs(dividend),n = labs(divisor),res = 0;
    while(m>=n){
        long tmp = n,cnt = 1;
        while(m>=(tmp<<1)){
            tmp<<=1;
            cnt<<=1;
        }
        m-=tmp;
        res+=cnt;
    }
    return sign == 1?res:-res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/divide-two-integers/
	return 0;
}

