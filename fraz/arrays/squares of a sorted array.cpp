using namespace std;
#include <bits/stdc++.h>
#define end "\n"
#define space " "

vector<int> sortedSquares(vector<int>& A){
    int n = A.size(),i=0,j=n-1;
    vector<int> res(n);
    for (int k = n-1; k >= 0; k--) {
        if(abs(A[i])>=abs(A[j])) res[k] = pow(A[i++],2);
        else res[k] = pow(A[j--],2);
    }
    return res;
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/squares-of-a-sorted-array/
    return 0;
}

