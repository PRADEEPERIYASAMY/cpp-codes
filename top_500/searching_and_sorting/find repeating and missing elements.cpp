using namespace std;
#include <bits/stdc++.h>

void getTwoElements(int arr[],int n){
    int x = 0,y = 0,xor1,setbit;
    xor1 = arr[0];
    for (int i = 1; i < n; i++) xor1^=arr[i];
    for (int i = 1; i <= n; i++) xor1^=i;
    setbit = xor1& ~(xor1-1); // rightmost set bit
    for (int i = 0; i < n; i++) {
        if(arr[i]&setbit) x^=arr[i];
        else y^=arr[i];
    }
    for (int i = 1; i <= n; i++) {
        if(i&setbit)x^=i;
        else y^=i;
    }
    cout<<x<<" "<<y;
}

int main(){
    int arr[] = { 1, 3, 4, 5, 5, 6, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    getTwoElements(arr, n);
    return 0;
}

