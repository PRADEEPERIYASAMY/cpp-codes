using namespace std;
#include <bits/stdc++.h>

//recusrsion
// string helper(const string &s,int &i){
//     string res;
//     while(i<s.length() && s[i] != ']'){
//         if(isalpha(s[i])) res+=s[i++];
//         else{
//             int num = 0;
//             while(isdigit(s[i])) num = num*10+(s[i++]-'0');
//             i++; //skip [
//             string temp = helper(s,i);
//             i++;// skip ]
//             while(num-->0){
//                 res+=temp;
//             }
//         }
//     }
//     return res;
// }

// string decodeString(string s) {
//     int i = 0;
//     return helper(s,i);
// }

//iterative
string decodeString(string s) {
    string str;
    int num = 0;
    stack<int> st;
    stack<string> sts;
    for (int i = 0; i < s.size(); i++) {
        if(isdigit(s[i])) num = num*10+(s[i]-'0');
        else if(s[i]=='['){
            st.push(num);
            num = 0;
            sts.push(str);
            str.clear();
        }else if(s[i] == ']'){
            int k = st.top();st.pop();
            while(k--){
                sts.top()+=str;
            }
            str = sts.top();sts.pop();
        }else str+=s[i];
    }
    return str;
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/decode-string/
    return 0;
}

