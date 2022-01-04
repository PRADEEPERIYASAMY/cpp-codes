#include <bits/stdc++.h>
using namespace std;

// recursion
// int lps(string str,int i,int j){
//     if(j == i) return 1;
//     if(str[i] == str[j] && i+1 == j) return 2;
//     if(str[i] == str[j]) return lps(str,i+1,j-1)+2;
//     return max(lps(str,i+1,j),lps(str,i,j-1));
// }

// dp
int lps(string str){
    int n = str.length();
    int L[n][n];
    for (int i = 0; i < n; i++) L[i][i] = 1;
    for (int gap = 2; gap <=n; gap++) {
        for (int i = 0; i < n-gap+1 ; i++) {
            int j = i+gap-1;
            if(str[i] == str[j] && gap == 2) L[i][j] = 2;
            else if(str[i] == str[j]) L[i][j] = L[i+1][j-1]+2;
            else L[i][j] = max(L[i][j-1],L[i+1][j]);
        }
    }
    return L[0][n-1];
}

int main(){
    string seq = "GEEKSFORGEEKS";
    int n = seq.length();
    //cout << "The length of the LPS is "<< lps(seq, 0, n-1);
    cout << "The length of the LPS is "<< lps(seq);
    return 0;
}

