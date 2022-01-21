using namespace std;
#include <bits/stdc++.h>

int FindMaxSum(vector<int> arr,int n){
    int inc = arr[0];
    int exc = 0;
    int exc_new;
    for (int i = 1; i < n; i++) {
        exc_new = max(inc,exc);
        inc = exc+arr[i];
        exc = exc_new;
    }
    return max(inc,exc);
}

int main(){
    vector<int> arr = {5, 5, 10, 100, 10, 5};
    cout<<FindMaxSum(arr, arr.size());
    return 0;
}

