#include <bits/stdc++.h>
using namespace std;
typedef pair<char,int> PAIR;

void rearrange(string &str,int d){
    int n = str.size();
    unordered_map<char,int> m;
    for (int i = 0; i < n; i++) {
        m[str[i]]++;
        str[i] = ' ';
    }
    auto comp = [](const PAIR &a,const PAIR &b){
        if(a.second <b.second) return true;
        else if(a.second>b.second) return false;
        else return a.first>b.first;
    };
    priority_queue<PAIR,vector<PAIR>,decltype(comp)> pq(m.begin(),m.end(),comp);
    while(!pq.empty()){
        auto x = pq.top();pq.pop();
        int p = 0;
        while(str[p] != ' ') p++;
        for (int i = 0; i < x.second; i++) {
            if(p+d*i>=n) {
                cout<<"cannot be rearranged";
                return;
            }
            str[p+d*i] = x.first;
        }
    }
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/rearrange-a-string-so-that-all-same-characters-become-at-least-d-distance-away/
	string str = "aabbcc";
    rearrange(str, 3);
    cout<<str;
    return 0;
}

