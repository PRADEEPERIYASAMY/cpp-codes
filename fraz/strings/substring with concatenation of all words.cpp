#include <iostream>
using namespace std;

// not working for few test case
// vector<int> findSubstring(string s, vector<string>& words) {
//     vector<int> res;
//     if(s.empty() || words.empty()) return res;
//     int n = words.size(),m = words[0].size();
//     unordered_map<string,int> mp;
//     for (auto &i : words) mp[i]++;
//     for (int i = 0; i < s.size() - n*m; i++) {
//         unordered_map<string,int> tmp;
//         int j = 0;
//         for (; j < n; j++) {
//             string t = s.substr(i+j*m,m);
//             if(!mp.count(t)) break;
//             tmp[t]++;
//             if(tmp[t]>mp[t]) break;
//         }
//         if(j == n) res.push_back(i);
//     }
//     return res;
// }

//working for all cases
vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> res;
    if(s.empty() || words.empty()) return res;
    int n = s.size(),cnt = words.size(),len = words[0].size();
    unordered_map<string,int> mp1;
    for (auto &i : words) mp1[i]++;
    for (int i = 0; i < len; i++) {
        int left = i,count = 0;
        unordered_map<string,int> mp2;
        for (int j = i; j <= n - len; j+=len) {
            string t = s.substr(j,len);
            if(mp1.count(t)){
                mp2[t]++;
                if(mp2[t]<=mp1[t]) count++;
                else{
                    while(mp2[t]>mp1[t]){
                        string t1 = s.substr(left,len);
                        mp2[t1]--;
                        if(mp2[t1]<mp1[t1]) count--;
                        left+=len;
                    }
                }
                if(count == cnt){
                    res.push_back(left);
                    mp2[s.substr(left,len)]--;
                    count--;
                    left+=len;
                }
            }else{
                mp2.clear();
                count = 0;
                left = j+len;
            }
        }
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/substring-with-concatenation-of-all-words/
	return 0;
}

