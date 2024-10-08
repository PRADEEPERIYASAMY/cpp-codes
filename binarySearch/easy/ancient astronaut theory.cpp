using namespace std;
#include <bits/stdc++.h>

bool isValid(char x,vector<int>&dict){
    return x-'a' >= 0 && x-'a' <= 25 && dict[x-'a'] != -1;
}

bool solve(string dictionary,string s){
    vector<int> dict(26,-1);
    for (int i = 0; i < dictionary.size(); i++) dict[dictionary[i]-'a'] = i;
    int n = s.size();
    int last = -1;
    for (int i = 0; i < n; i++) {
        if(isValid(s[i],dict)){
            if(dict[s[i]-'a']<last) return false;
            last = dict[s[i]-'a'];
        }
    }
    return true;
}

int main(){
    cout<<solve("acb","aaaa h ccc i bbb");
    return 0;
}

