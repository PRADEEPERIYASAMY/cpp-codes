#include <bits/stdc++.h>
using namespace std;
#define MAX_CAHR 26

struct key{
    int freq;
    char ch;
};

void rearrangeString(string str){
    int n = str.size();
    int count[MAX_CAHR] = {0};
    for (int i = 0; i < n; i++) count[str[i]-'a']++;
    auto cmp = [](const key &a,const key &b){
      return a.freq<b.freq;  
    };
    priority_queue<key,vector<key>,decltype(cmp)> pq(cmp);
    for (char ch = 'a'; ch <= 'z'; ch++) {
        int val = ch - 'a';
        if(count[val]) pq.push({count[val],ch});
    }
    str = "";
    key prev = {-1,'#'};
    while(!pq.empty()){
        auto t = pq.top();pq.pop();
        str = str+t.ch;
        if(prev.freq>0) pq.push(prev);
        t.freq--;
        prev = t;
    }
    if(n != str.size()) cout<<"Not valid string"<<endl;
    else cout<<str<<endl;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/rearrange-characters-string-no-two-adjacent/
	string str = "bbbaa";
    rearrangeString(str);
    return 0;
}

