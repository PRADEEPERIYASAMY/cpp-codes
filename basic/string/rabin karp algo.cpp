#include <iostream>
#include <bits/stdc++.h> 
using namespace std;
#define d 256
const int q=101;

// this alog use hash to do fast(hash fro previous hash)
void RBSearch(string pat,string txt,int m,int n){
    int h = 1;
    for (int i = 1; i < m; i++) h = (h*d)%q;
    int p = 0,t = 0;
    for (int i = 0; i < m; i++) {
        p = (p*d+pat[i])%q;
        t = (t*d+txt[i])%q;
    }
    
    for (int i = 0; i <= (n-m); i++) {
        if(p == t){
            bool flag = true;
            for (int j = 0; j <m; j++) 
                if(txt[i+j] != pat[j]){
                    flag = false;
                    break;
                }
            if(flag) cout<<i<<" ";
        }
        if(i<(n-m)){
            t = ((d*(t-txt[i]*h))+txt[i+m])%q;
            if(t<0) t+=q;
        }
    }
}

int main() 
{ 
    string txt = "GEEKS FOR GEEKS";string pat="GEEK";
    cout<<"All index numbers where pattern found:"<<" ";
    RBSearch(pat,txt,4,15);
    return 0; 
} 

