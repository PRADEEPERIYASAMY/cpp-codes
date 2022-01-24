using namespace std;
#include <bits/stdc++.h>
#define end "\n"
#define space " "

int digitSquareSum(int num){
    int sum = 0,tmp;
    while(num){
        tmp = num%10;
        sum+=(tmp*tmp);
        num/=10;
    }
    return sum;
}

bool isHappy(int n){
    int slow,fast;
    slow = fast = n;
    do{
        slow = digitSquareSum(slow);
        fast = digitSquareSum(digitSquareSum(fast));
    }while(slow!=fast);
    if(slow == 1) return true;
    return false;
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/happy-number/discuss/117136/c++-using-Floyd-Cycle-Detection-Algorithm
    return 0;
}

