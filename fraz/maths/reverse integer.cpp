using namespace std;
#include <bits/stdc++.h>
#define end "\n"
#define space " "

int reverse(int x) {
    long res = 0;
    while(x!= 0){
        res = res*10+x%10;
        x/=10;
    }
    return (res<INT_MIN || res>INT_MAX)?0:(int)res;
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/reverse-integer/
    return 0;
}

