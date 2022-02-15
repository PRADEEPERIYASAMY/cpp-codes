#include <iostream>
using namespace std;

bool isValid(const string &str){
    int cnt = 0;
    for (auto &c : str) {
        if(c == '(') cnt++;
        else if(c == ')' && --cnt<0) return false;
    }
    return cnt == 0;
}

vector<string> removeInvalidParentheses(string s) {
    vector<string> res;
    unordered_set<string> visited({s});
    queue<string> q({s});
    bool found = false;
    while(!q.empty()){
        string t = q.front();q.pop();
        if(isValid(t)){
            res.push_back(t);
            found = true;
        }
        if(found) continue;
        for (int i = 0; i < t.size(); i++) {
            if(t[i]!='(' && t[i]!=')') continue;
            string str = t.substr(0,i)+t.substr(i+1);
            if(!visited.count(str)){
                q.push(str);
                visited.insert(str);
            }
        }
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/remove-invalid-parentheses/
	return 0;
}

