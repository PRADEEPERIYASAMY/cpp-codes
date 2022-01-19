using namespace std;
#include <bits/stdc++.h>

void printArr(int arr[], int n){
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

void generateUtil(int A[],int B[],int C[],int i,int j,int m,int n,int len,bool flag ){
    if(flag){
        if(len) printArr(C,len+1);
        for (int k = i; k < m; k++) {
            if(!len){
                C[len] = A[k];
                generateUtil(A,B,C,k+1,j,m,n,len,!flag);
            }else{
                if(A[k]>C[len]){
                    C[len+1] = A[k];
                    generateUtil(A,B,C,k+1,j,m,n,len+1,!flag);
                }
            }
        }
    }else{
        for (int l = j; l < n; l++) {
            if(B[l]>C[len]) {
                C[len+1] = B[l];
                generateUtil(A,B,C,i,l+1,m,n,len+1,!flag);
            }
        }
    }
}

void generate(int A[],int B[],int m,int n){
    int C[m+n];
    generateUtil(A,B,C,0,0,m,n,0,true);
}

int main(){
    int A[] = {10, 15, 25};
    int B[] = {5, 20, 30};
    int n = sizeof(A)/sizeof(A[0]);
    int m = sizeof(B)/sizeof(B[0]);
    generate(A, B, n, m);
    return 0;
}

