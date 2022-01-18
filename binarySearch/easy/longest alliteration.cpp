using namespace std;
#include <bits/stdc++.h>

int solve(vector<string> &words){
    int count = 1;
    int m = 1;
    if(words.empty()) return 0;
    for (int i = 0; i+1 < words.size(); i++) {
        if(words[i][0] == words[i+1][0]) count++;
        else count = 1;
        m = max(count,m);
    }
    return m;
}

int main(){
    vector<string> str = {"she", "sells", "seashells", "he", "sells", "clams"};
    cout<<solve(str);
    return 0;
}

