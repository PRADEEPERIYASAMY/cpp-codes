using namespace std;
#include <bits/stdc++.h>
#define M 4
#define N 5

int findCommon(int mat[M][N]){
    unordered_map<int,int> mp;
    int i,j;
    for (int i = 0; i < M; i++) {
        mp[mat[i][0]]++;
        for (int j = 1; j < N; j++) {
            if(mat[i][j] != mat[i][j-1]) mp[mat[i][j]]++;
        }
    }
    for (auto &i : mp) {
        if(i.second == M) return i.first;
    }
    return -1;
}

int main(){
    int mat[M][N] = {
        { 1, 2, 3, 4, 5 },
        { 2, 4, 5, 8, 10 },
        { 3, 5, 7, 9, 11 },
        { 1, 3, 5, 7, 9 },
    };
    int result = findCommon(mat);
    if (result == -1) cout << "No common element";
    else cout << "Common element is " << result;
    return 0;
}

