using namespace std;
#include <bits/stdc++.h>
#define end "\n"
#define space " "

string addStrings(string num1, string num2) {
    string res;
    int m = num1.size(),n = num2.size();
    int i = m-1,j = n-1,carry = 0;
    while(i>=0 || j>=0 || carry){
        int n1 = i>=0?num1[i--]-'0':0;
        int n2 = j>=0?num2[j--]-'0':0;
        int sum = n1+n2+carry;
        res+=(char)(sum%10+'0');
        carry=sum/10;
    }
    reverse(res.begin(),res.end());
    return res;
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/add-strings/
    return 0;
}

