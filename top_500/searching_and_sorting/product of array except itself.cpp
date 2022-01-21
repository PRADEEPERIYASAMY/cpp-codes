using namespace std;
#include <bits/stdc++.h>
#define end "\n"
#define space " "

long* productExceptSelf(int arr[],int n){
    long prod = 1;
    long flag = 0;
    for (int i = 0; i < n; i++) {
        if(arr[i] == 0) flag++;
        else prod*=arr[i];
    }
    long* out = new long[n];
    for (int i = 0; i < n; i++) {
        if(flag>1) out[i] = 0;
        else if(flag == 0) out[i] = prod/arr[i];
        else if(flag == 1 && arr[i]!=0) out[i] = 0;
        else out[i] = prod;
    }
    return out;
}

int main(){
    int array[] = { 10, 3, 5, 6, 2 };
    int n = sizeof(array)/sizeof(array[0]);
    long* ans;
    ans = productExceptSelf(array, n);
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    return 0;
}

