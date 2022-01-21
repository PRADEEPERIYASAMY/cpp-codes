using namespace std;
#include <bits/stdc++.h>

float md2(int a,int b){return (a+b)/2.0;}

float md3(int a,int b,int c){ return a+b+c - max({a,b,c})-min({a,b,c});}

float md4(int a,int b,int c,int d){return (a+b+c+d - max({a,b,c,d}) - min({a,b,c,d}))/2;}

float medianSingle(int arr[],int n){
    if(n == 0) return -1;
    if(n%2 == 0) return (double)(arr[n/2]+arr[n/2-1])/2;
    return arr[n/2];
}

float findMedianUtil(int arr1[],int n,int arr2[],int m){
    if(n == 0) return medianSingle(arr2,m);
    if(n == 1) {
        if(m == 1) return md2(arr1[0],arr2[0]);
        if(m%2 != 0) return md2(arr2[m/2],md3(arr1[0],arr2[m/2-1],arr2[m/2+1]));
        return md3(arr2[m/2],arr2[m/2-1],arr1[0]);
    }else if(n == 2){
        if(m == 2) return md4(arr1[0],arr1[1],arr2[0],arr2[1]);
        if(m%2 != 0) return md3(arr2[m/2],max(arr1[0],arr2[m/2-1]),min(arr1[1],arr2[m/2+1])); 
        return md4(arr2[m/2],arr2[m/2-1],max(arr1[0],arr2[m/2-2]),min(arr1[1],arr2[m/2+1]));
    }
    int idxa = (n-1)/2;
    int idxb = (m-1)/2;
    if(arr1[idxa]<=arr2[idxb]) return findMedianUtil(arr1+idxa,n/2+1,arr2,m-idxa);
    return findMedianUtil(arr1,n/2+1,arr2+idxa,m-idxa);
}

float findMedian(int arr1[],int n,int arr2[],int m){
    if(n>m) return findMedianUtil(arr2,m,arr1,n);
    return findMedianUtil(arr1,n,arr2,m);
}

int main(){
    int A[] = {900};
    int B[] = {5, 8, 10, 20};
    int N = sizeof(A) / sizeof(A[0]);
    int M = sizeof(B) / sizeof(B[0]);
    printf("%f", findMedian( A, N, B, M ) );
    return 0;
}

