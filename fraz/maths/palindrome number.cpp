using namespace std;
#include <bits/stdc++.h>
#define end "\n"
#define space " "

bool isPalindrome(int x) {
    if(x<0) return false;
    int orig = x;
    long num = 0;
    while(x){
        num = num*10+x%10;
        x/=10;
    }
    return orig == num;
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/palindrome-number/
    return 0;
}

