using namespace std;
#include <bits/stdc++.h>
#define end "\n"
#define space " "

int fib(int N){
    if(N == 0) return 0;
    int a = 0,b = 1;
    for (int i = 2; i <= N; i++) {
        int c = a+b;
        a = b;
        b = c;
    }
    return b;
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/fibonacci-number/
    return 0;
}

