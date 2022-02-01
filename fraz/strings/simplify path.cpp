#include <iostream>
using namespace std;

string simplifyPath(string path) {
    string res,tmp;
    istringstream iss(path);
    vector<string> st;
    while(getline(iss,tmp,'/')){
        if(tmp.empty() || tmp == ".")continue;
        if(tmp == ".."){
            if(!st.empty()) st.pop_back();
        }
        else st.push_back(tmp);
    }
    for (auto &i : st) res+="/"+i;
    return res.empty()?"/":res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/simplify-path/
	return 0;
}

