using namespace std;
#include <bits/stdc++.h>
#define R 4
#define C 4

int maxHist(int arr[]){
    stack<int> s;
    int res =0,tp,cur;
    s.push(0);
    for (int i = 0; i < C; i++) {
        while(!s.empty() && arr[s.top()]>=arr[i]){
            tp = s.top();s.pop();
            cur = arr[tp]*(s.empty()?i:i-s.top()-1);
            res = max(res,cur);
        }
        s.push(i);
    }
    while(!s.empty()){
        tp = s.top();s.pop();
        cur = arr[tp]*(s.empty()?C:C-s.top()-1);
        res = max(res,cur);
    }
    return res;
}

int maxRectangle(int A[][C]){
    int result = maxHist(A[0]);
    for (int i = 1; i < R; i++) {
        for (int j = 0; j < C; j++) if(A[i][j]) A[i][j]+=A[i-1][j];
        result = max(result,maxHist(A[i]));
    }
    return result;
}

int main(){
    int A[][C] = {
        { 0, 1, 1, 0 },
        { 1, 1, 1, 1 },
        { 1, 1, 1, 1 },
        { 1, 1, 0, 0 },
    };

    cout << "Area of maximum rectangle is "<< maxRectangle(A);
    return 0;
}

