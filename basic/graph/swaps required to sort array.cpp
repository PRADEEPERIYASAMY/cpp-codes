#include <bits/stdc++.h> 
using namespace std; 


int minSwaps(vector<int> arr, int n){
    int ans = 0;
    vector<int> temp = arr;
    map<int,int> h;
    sort(temp.begin(),temp.end());
    for (int i = 0; i < n; i++) h[arr[i]] = i;
    for (int i = 0; i < n; i++) {
        if(arr[i] != temp[i]){
            ans++;
            int ind = h[temp[i]];
            int el = arr[i];
            swap(arr[i],arr[ind]);
            h[el] = ind;
            h[temp[i]] = i;
        }
    }
    return ans;
}

int main(){
    vector <int> a = {101, 758, 315, 730, 472, 619,460, 479};
    int n = a.size();

    cout << minSwaps(a, n);
    return 0;
}

