#include <bits/stdc++.h>
using namespace std;

// using stack 
// int findMaxLen(string str){
//     int n = str.size();
//     stack<int> st;
//     st.push(-1);
//     int result = 0;
//     for (int i = 0; i < n; i++) {
//         if(str[i] == '(') st.push(i);
//         else{
//             if(!st.empty()) st.pop();
//             if(!st.empty()) result = max(result,i - st.top());
//             else st.push(i);
//         }
//     }
//     return result;
// }

// using dp 
// int findMaxLen(string s){
//     if(s.size()<=1) return 0;
//     int curmax = 0;
//     vector<int> longest(s.size(),0);
//     for (int i = 1; i < s.size(); i++) {
//         if (s[i] == ')' && i - longest[i - 1] - 1 >= 0&& s[i - longest[i - 1] - 1] == '('){
//             longest[i] = longest[i - 1] + 2
//                   + ((i - longest[i - 1] - 2 >= 0)
//                   ? longest[i - longest[i - 1] - 2]
//                   : 0);
//         }
//     }
//     return *max_element(longest.begin(),longest.end());
// }

int findMaxLen(string s){
    int n = s.size();
    int left = 0,right = 0,maxlen = 0;
    for (int i = 0; i < n; i++) {
        if(s[i] == '(') left++;
        else right++;
        if(left == right) maxlen = max(maxlen,2*left);
        else if(right>left) left = right = 0;
    }
    left = right = 0;
    for (int i = n-1; i >= 0; i--) {
        if(s[i] == '(') left++;
        else right++;
        if(left == right) maxlen = max(maxlen,2*left);
        else if(left>right) left = right = 0;
    }
    return maxlen;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/length-of-the-longest-valid-substring/
	string str = "((()()";
    cout << findMaxLen(str) << endl;
    str = "()(()))))";
    cout << findMaxLen(str) << endl;
    return 0;
}