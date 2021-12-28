#include <iostream>
#include <bits/stdc++.h> 
using namespace std; 

// recursive i = 0, j = n-1

bool isPalindrome(string s,int i,int j){
    while(i<=j){
        if(s[i]!= s[j]) return false;
        i++;
        j--;
    }
    return true;
}

// int palPart(string s,int i, int j){
//     if(isPalindrome(s,i,j)) return 0;
    
//     int res = INT_MAX;
    
//     for (int k = i; k <j; k++) {
//          res = min(res,1+palPart(s,i,k)+palPart(s,k+1,j));
//     }
//     return res;
// }

// dp
int palPart(string s){
    int n = s.length();
    int dp[n][n];
    for (int i = 0; i < n; i++) dp[i][i] = 0;
    
    for (int g = 1; g < n; g++) {
        for (int i = 0; i+g < n; i++) {
            int j = i+g;
            if(isPalindrome(s,i,j)) dp[i][j] = 0;
            else{
                dp[i][j] = INT_MAX;
                for (int k = i; k < j; k++) dp[i][j] = min(dp[i][j],1+dp[i][k]+dp[k+1][j]);
            }
        }
    }
    
    return dp[0][n-1];
}

int main() {
    	string s = "geek";
    	//cout<<palPart(s,0,s.length()-1);
    	cout<<palPart(s);
    	return 0;
}

