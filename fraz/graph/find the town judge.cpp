using namespace std;
#include <bits/stdc++.h>

int findJudge(int N, vector<vector<int>>& trust){
    vector<int> degree(N+1,0);
    for (auto &i : trust) degree[i[0]]--,degree[i[1]]++;
    for (int i = 1; i <= N; i++) if(degree[i] == N-1) return i;
    return -1;
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/find-the-town-judge/
    return 0;
}

