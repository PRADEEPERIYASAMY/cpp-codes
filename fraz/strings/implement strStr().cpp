using namespace std;
#include <bits/stdc++.h>
#define end "\n"
#define space " "

// using rabin karp
int strStr(string haystack, string needle) {
    int q = 101;
    int d = 256;
    int m = needle.size();
    int n = haystack.size();
    int i,j;
    int p = 0,t = 0;
    int h = 1;
    for (i = 0; i < m-1; i++) h=(h*d)%q;
    for (i = 0; i < m; i++) {
        p = (d*p+needle[i])%q;
        t = (d*t+haystack[i])%q;
    }
    for (i = 0; i <=n-m; i++) {
        if(p == t){
            for (j = 0; j < m; j++) if(haystack[i+j] != needle[j])break;
            if(j == m) return i;
        }
        if(i<n-m){
            t = (d*(t- haystack[i]*h)+haystack[i+m])%q;
            if(t<0) t = t+q;
        }
    }
    return -1;
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/implement-strstr/
    return 0;
}

