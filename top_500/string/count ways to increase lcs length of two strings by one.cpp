#include <bits/stdc++.h>
using namespace std;
#define M 26

int toInt(char ch){return (ch - 'a');}

int waysToIncreaseLCSBy1(string str1,string str2){
    int m = str1.size(),n = str2.size();
    vector<int> position[M];
    for (int i = 1; i <= n; i++) position[toInt(str2[i-1])].push_back(i);
    int lcs[m+2][n+2],lcsr[m+2][n+2];
    memset(lcs,0,sizeof(lcs));
    memset(lcsr,0,sizeof(lcsr));
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if(str1[i-1] == str2[j-1]) lcs[i][j] = 1+lcs[i-1][j-1];
            else lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
        }
    }
    
    for (int i = m; i >= 1; i--) {
        for (int j = n; j >= 1; j--) {
            if(str1[i-1] == str2[j-1]) lcsr[i][j] = 1+lcsr[i+1][j+1];
            else lcsr[i][j] = max(lcsr[i+1][j],lcsr[i][j+1]);
        }
    }
    int ways = 0;
    for (int i = 0; i <= m; i++) {
        for (char c = 'a'; c <= 'z'; c++) {
            for (int j = 0; j <position[toInt(c)].size(); j++) {
                int p = position[toInt(c)][j];
                if(lcs[i][p-1]+lcsr[i+1][p+1] == lcs[m][n]) ways++;
            }
        }
    }
    return ways;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/count-ways-increase-lcs-length-two-strings-one/
	string str1 = "abcabc";
    string str2 = "abcd";
    cout << waysToIncreaseLCSBy1(str1, str2);
    return 0;
}

