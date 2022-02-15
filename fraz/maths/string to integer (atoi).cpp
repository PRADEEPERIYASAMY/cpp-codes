#include <iostream>
using namespace std;

int myAtoi(string str) {
    if(str.empty()) return 0;
    int idx = 0,sign = 1,n = str.size();
    while(str[idx] == ' ' && idx<n) idx++;
    if(idx == n) return 0;
    long res = 0;
    if(str[idx] == '+' || str[idx] == '-') sign = 44 - str[idx++];
    while(idx<n){
        if(str[idx]>='0' && str[idx]<= '9') res = res*10+(str[idx++] - '0');
        else break;
        if(res>INT_MAX) return sign == 1? INT_MAX:INT_MIN;
    }
    return sign*res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/string-to-integer-atoi/
	return 0;
}

