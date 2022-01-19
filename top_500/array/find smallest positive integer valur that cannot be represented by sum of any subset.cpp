using namespace std;
#include <bits/stdc++.h>

int smallestpositive(vector<long long> arr,int n){
    int res = 1;
    for (int i = 0; i < n && arr[i]<=res; i++) res+=arr[i];
    return res;
}

int main(){
    vector<long long> arr4 = {1, 1, 3, 4};
    cout << smallestpositive(arr4, arr4.size()) << endl;
    return 0;
}

