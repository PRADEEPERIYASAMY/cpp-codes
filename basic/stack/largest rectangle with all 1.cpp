#include <bits/stdc++.h> 
using namespace std; 

#define R 4 
#define C 4

int getMaxArea(int arr[],int n){
    int res = 0,curr,tp;
    stack<int> s;
    s.push(0);
    for (int i = 0; i < n; i++) {
        while(!s.empty() && arr[s.top()]>=arr[i]){
            tp=s.top();s.pop();
            curr = arr[tp]*(s.empty()?i:i-s.top()-1);
            res = max(res,curr);
        }
        s.push(i);
    }
    while(!s.empty()){
        tp = s.top();s.pop();
        curr = arr[tp]*(s.empty()?n:n-s.top()-1);
        res = max(res,curr);
    }
    return res;
}

int maxRectangle(int mat[][C]){
    int res = getMaxArea(mat[0],C);
    for (int i = 1; i < R; i++) {
        for (int j = 0; j < C; j++) if(mat[i][j]) mat[i][j]+=mat[i][j];
        res = max(res,getMaxArea(mat[i],C));
    }
    return res;
}

int main() {
    int mat[][C] = { 
        { 0, 1, 1, 0 }, 
        { 1, 1, 1, 1 }, 
        { 1, 1, 1, 1 }, 
        { 1, 1, 0, 0 }, 
    }; 
    cout << "Area of maximum rectangle is " << maxRectangle(mat); 
    return 0;   
}

