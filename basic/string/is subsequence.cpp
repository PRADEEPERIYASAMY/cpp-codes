#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

// iterative
// bool isSubSeq(string s1,string s2,int m,int n){
//     int j = 0;
//     for (int i = 0; i < m && j< n; i++) {
//         if(s1[i] == s2[j]) j++;
//     }
//     return j == n;
// }

// recursive
bool isSubSeq(string s1,string s2,int m,int n){
    if(m == 0) return true;
    if(n == 0) return false;
    if(s1[m-1] == s2[n-1]) return isSubSeq(s1,s2,m-1,n-1);
    return isSubSeq(s1,s2,m-1,n);
}

int main() {
	cout<<isSubSeq("ABCDEF", "ABD", 6, 3);
	return 0;
}

