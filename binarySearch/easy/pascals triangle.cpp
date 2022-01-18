using namespace std;
#include <bits/stdc++.h>

vector<int> solve(int n){
    vector<int> temp;
    temp.push_back(1);
    while(n--){
        for (int i = temp.size()-1; i >0; i--) temp[i]+=temp[i-1];
        temp.push_back(1);
    }
    return temp;
}

int main(){
    for (auto &i : solve(3)) cout<<i<<" ";
    return 0;
}

