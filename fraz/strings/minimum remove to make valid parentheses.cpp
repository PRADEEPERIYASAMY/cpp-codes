#include <iostream>
using namespace std;

//with stack
// string minRemoveToMakeValid(string s) {
//     stack<int> st;
//     for (int i = 0; i < s.size(); i++) {
//         if(s[i] == '(') st.push(i);
//         else if(s[i] == ')'){
//             if(st.empty()) s[i] ='#';
//             else st.pop();
//         }
//     }
//     while(!st.empty()){
//         s[st.top()] = '#';
//         st.pop();
//     }
//     string res = "";
//     for (int i = 0; i < s.size(); i++) if(s[i] != '#') res.push_back(s[i]);
//     return res;
// }

//without stack
string minRemoveToMakeValid(string s) {
    int n =s.size();
    int count = 0;
    for (int i = 0; i < n; i++) {
        if(s[i] == '(') count++;
        else if(s[i] == ')'){
            if(count == 0) s[i] = '#';
            else count--;
        }
    }
    count = 0;
    for (int i = n-1; i >= 0; i--) {
        if(s[i] == ')') count++;
        else if(s[i] == '('){
            if(count == 0) s[i] = '#';
            else count--;
        }
    }
    string res = "";
    for (int i = 0; i < n; i++) if(s[i] != '#') res.push_back(s[i]);
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/discuss/1073189/C%2B%2B-or-2-Approaches-or-O(n)-Beats-100-or-No-Extra-Space-(Best)-or-Explanation
	return 0;
}

