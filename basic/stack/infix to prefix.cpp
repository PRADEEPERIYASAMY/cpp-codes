#include <bits/stdc++.h> 
using namespace std; 

int prec(char c){
    if(c == '^') return 3;
    else if(c == '/' || c == '*') return 2;
    else if(c == '+' || c == '-') return 1;
    else return -1;
}

string infixToPostfix(string s){
    stack<char> st;
    string result;
    for (int i = 0; i < s.length(); i++) {
        char c =s[i];
        if((c>='a'&&c<='z') || (c>='A'&&c<='Z') || (c>='0'&&c<='9')) result+=c;
        else if(c == '(') st.push('(');
        else if(c == ')'){
            while(st.top() != '('){
                result+=st.top();
                st.pop();
            }
            st.pop();
        }else{
            if(s[i] == '^'){
                while(!st.empty() && prec(s[i])<= prec(st.top())){ // chamge than original algo for prefix
                    result+=st.top();
                    st.pop();
                }
            }else{
                while(!st.empty() && prec(s[i])< prec(st.top())){
                    result+=st.top();
                    st.pop();
                }
            }
            st.push(c);
        }
    }
    while(!st.empty()){
        result+=st.top();
        st.pop();
    }
    return result;
}

string infixToPrefix(string s){
    int n = s.length();
    reverse(s.begin(),s.end());
    for (int i = 0; i < n; i++) {
        if(s[i] == '(') s[i] = ')';
        else if(s[i] == ')') s[i] = '(';
    }
    string prefix = infixToPostfix(s);
    reverse(prefix.begin(),prefix.end());
    return prefix;
}

int main() {
    string s = ("x+y*z/w+u");
    cout << infixToPrefix(s) << std::endl;
    return 0;
}

