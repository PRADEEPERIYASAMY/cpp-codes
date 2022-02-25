#include <bits/stdc++.h>
using namespace std;
#define MAX 100
int lcsLen = 0;
int dp[MAX][MAX];

int lcs(string str1,string str2,int len1,int len2,int i,int j){
    int &ret = dp[i][j];
    if(i == len1 || j == len2) return ret = 0;
    if(ret != -1) return ret;
    ret = 0;
    if(str1[i] == str2[j]) ret = 1+lcs(str1,str2,len1,len2,i+1,j+1);
    else ret = max(lcs(str1,str2,len1,len2,i+1,j),lcs(str1,str2,len1,len2,i,j+1));
    return ret;
}

void printAll(string str1,string str2,int len1,int len2,string data,int index1,int index2,int curlen){
    if(curlen == lcsLen) {
        cout<<data<<"\n";
        return;
    }
    if(index1 == len1 || index2 == len2) return;
    for (char ch = 'a'; ch <= 'z'; ch++) {
        bool done = false;
        for (int i = index1; i < len1; i++) {
            if(ch == str1[i]){
                for (int j = index2; j <len2; j++) {
                    if(ch == str2[j] && dp[i][j] == lcsLen - curlen){
                        data.push_back(ch);
                        printAll(str1,str2,len1,len2,data,i+1,j+1,curlen+1);
                        data.pop_back();
                        done = true;
                        break;
                    }
                }
            }
            if(done) break;
        }
    }
}

void printAllLCSSorted(string str1,string str2){
    int len1 = str1.size(),len2 = str2.size();
    memset(dp,-1,sizeof(dp));
    lcsLen = lcs(str1,str2,len1,len2,0,0);
    string data;
    printAll(str1,str2,len1,len2,data,0,0,0);
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/print-longest-common-sub-sequences-lexicographical-order/
    string str1 = "abcabcaa", str2 = "acbacba";
    printAllLCSSorted(str1,str2);
    return 0;
}

