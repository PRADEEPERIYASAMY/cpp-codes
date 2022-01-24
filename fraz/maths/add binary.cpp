using namespace std;
#include <bits/stdc++.h>
#define end "\n"
#define space " "

string addBinary(string a, string b) {
    int m = a.size(),n = b.size(),carry = 0;
    string res;
    for (int i = m-1,j = n-1;i>=0||j>=0||carry>0;i--,j--) {
        int temp = (i>=0?(a[i]-'0'):0)+(j>=0?(b[j]-'0'):0)+carry;
        carry = temp/2;
        temp%=2;
        res+=(temp+'0');
    }
    reverse(res.begin(),res.end());
    return res;
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/add-binary/
    return 0;
}

