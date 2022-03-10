#include <bits/stdc++.h>
using namespace std;

int prec(char c){
    if(c == '^') return 3;
    else if(c == '/' || c == '*') return 2;
    else if(c == '+' || c == '-') return 1;
    else return -1;
}

void infixToPostfix(string s){
    stack<char> st;
    string result;
    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];
        if(isalpha(ch)) result+=ch;
        else if(ch == '(') st.push('(');
        else if(ch == ')'){
            while(st.top() != '('){
                result+=st.top();
                st.pop();
            }
            st.pop();
        }else{
            while(!st.empty() && prec(ch)<=prec(st.top())){
                result +=st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    while(!st.empty()){
        result+=st.top();
        st.pop();
    }
    cout<<result<<"\n";
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/stack-set-2-infix-to-postfix/
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(exp);
    return 0;
}
