using namespace std;
#include <bits/stdc++.h>

int solve(vector<int>&nums){
    int flips = 0,now = 1;
    for (auto &i : nums) {
        if(i == now){
            flips++;
            now = 1-now;
        }
    }
    return flips;
}

int main(){
    vector<int> arr = {1, 1, 0};
    cout<<solve(arr);
    return 0;
}

