using namespace std;
#include <bits/stdc++.h>
#define N 5

void fillLps(string str,int lps[]){
    int n = str.size(),len = 0;
    lps[0] = 0;
    int i = 1;
    while(i<n){
        if(str[i] == str[len]) {
            lps[i] = len+1;
            i++;len++;
        }else{
            if(len == 0){
                lps[i] = 0;i++;
            }else len = lps[len - 1];
        }
    }
}

int KMP(string pat,string txt){
    int n = txt.size();
    int m = pat.size();
    int lps[m];
    fillLps(pat,lps);
    int i =0,j =0;
    while(i<n){
        if(pat[j] == txt[i]){
            i++;j++;
        }
        if(j == m){
            //cout<<i-j<<" ";
            //j = lps[j-1];
            return 1;
        }else if(i<n && pat[j] != txt[i]){
            if(j == 0) i++;
            else j = lps[j-1];
        }
    }
    return 0;
}

void findOrientation(char mat[][N],string pat){
    for (int i = 0; i < N; i++) {
        string txt1 = "",txt2 = "";
        for (int j = 0; j < N; j++){
            txt1+=mat[i][j];
            txt2+=mat[j][i];
        }
        if(KMP(pat,txt1)) cout<<"Horizantal";
        else if(KMP(pat,txt2)) cout<<"Vertical";
    }
}

int main(){
    char mat[N][N] = {{'a', 'b', 'c', 'd', 'e'},
                      {'f', 'g', 'h', 'i', 'j'},
                       {'k', 'l', 'm', 'n', 'o'},
                      {'p', 'q', 'r', 's', 't'},
                      {'u', 'v', 'w', 'x', 'y'}};
    string pat = "pqrs";
    findOrientation(mat, pat);
    return 0;
}

