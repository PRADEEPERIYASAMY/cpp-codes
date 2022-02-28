#include <bits/stdc++.h>
using namespace std;

// int findMaxLen(string str){
//     int n = str.size();
//     stack<int> st({-1}); // -1 as base
//     int result = 0;
//     for (int i = 0; i < n; i++) {
//         if(str[i] == '(') st.push(i);
//         else {
//             if(!st.empty()) st.pop();
//             if(!st.empty()) result = max(result,i-st.top());
//             else st.push(i); // is st is empty then this the base
//         }
//     }
//     return result;
// }

int findMaxLen(string str){
    int n = str.size();
    int left = 0,right = 0,maxLength = 0;
    for (int i = 0; i < n; i++) {
        if(str[i] == '(') left++;
        else right++;
        if(left == right) maxLength = max(maxLength,2*right);
        else if(right>left) left = right = 0;
    }
    left = right = 0;
    for (int i = n-1; i >= 0; i--) {
        if(str[i] == '(') left++;
        else right++;
        if(left == right) maxLength = max(maxLength,2*left);
        else if(left>right) left = right = 0;
    }
    return maxLength;
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

