using namespace std;
#include <bits/stdc++.h>
#define end "\n"
#define space " "

bool isPalin(string s,int left,int right){
    while(left<right){
        if(s[left]!=s[right]) return false;
        left++;
        right--;
    }
    return true;
}

bool validPalindrome(string s){
    int left = 0,right = s.size()-1;
    while(left<right){
        if(s[left]!=s[right]) return isPalin(s,left+1,right) || isPalin(s,left,right-1);
        left++;
        right--;
    }
    return true;
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/valid-palindrome-ii/
    return 0;
}

