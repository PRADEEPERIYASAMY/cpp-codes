#include <iostream>
using namespace std;

// dp

// https://www.geeksforgeeks.org/maximum-size-sub-matrix-with-all-1s-in-a-binary-matrix/

#include <bits/stdc++.h>
#define R 6
#define C 5

void printMaxSubSquare(int M[R][C]){
    int s[R][C];
    
    for (int i = 0; i < R; i++) s[i][0] = M[i][0];
    
    for (int i = 0; i < C; i++) s[0][i] = M[0][i];
    
    for (int i = 1; i < R; i++) {
        for (int j = 1; j < C; j++) {
            if(M[i][j] == 1){
                s[i][j] = min(s[i-1][j],min(s[i][j-1],s[i-1][j-1]))+1;
            }else{
                s[i][j] = 0;
            }
        }
    }
    
    int max_ = s[0][0],max_i = 0,max_j = 0;
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if(s[i][j]>max_){
                max_ = s[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }
    
    for (int i = max_i; i > max_i - max_; i--) {
        for (int j = max_j; j > max_j - max_; j--) {
            cout<<M[i][j]<<" ";
        }
        cout<<endl;
    }
    
}

int main()
{
    int M[R][C] = {{0, 1, 1, 0, 1},
                    {1, 1, 0, 1, 0},
                    {0, 1, 1, 1, 0},
                    {1, 1, 1, 1, 0},
                    {1, 1, 1, 1, 1},
                    {0, 0, 0, 0, 0}};
                     
    printMaxSubSquare(M);
    
    return 0;
}

