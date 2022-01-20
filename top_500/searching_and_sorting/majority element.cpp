using namespace std;
#include <bits/stdc++.h>

int findCandidate(int arr[],int n){
    int ind = 0,count = 1;
    for (int i = 1; i < n; i++) {
        if(arr[ind] == arr[i]) count++;
        else count--;
        if(count == 0){
            ind =i;
            count = 1;
        }
    }
    return arr[ind];
}

bool isMajority(int arr[],int n,int k){
    int count = 0;
    for (int i = 0; i < n; i++) if(arr[i] == k) count++;
    return count>n/2?1:0;
}

void printMajority(int arr[],int n){
    int cand = findCandidate(arr,n);
    if(isMajority(arr,n,cand)) cout<<cand;
    else cout<<"No majority";
}

int main(){
    int a[] = { 1, 3, 3, 1, 3 };
    int size = (sizeof(a)) / sizeof(a[0]);
    printMajority(a, size);
    return 0;
}

