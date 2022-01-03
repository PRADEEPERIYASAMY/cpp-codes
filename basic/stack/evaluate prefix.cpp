#include <bits/stdc++.h> 
using namespace std; 

int evaluatePrefix(string s){
    stack<int> st;
    for (int i = s.length()-1; i >= 0; i--) {
        if(isdigit(s[i])) st.push(s[i]-'0');
        else{
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();
            switch(s[i]){
                case '+':st.push(val2+val1);break;
                case '-':st.push(val2-val1);break;
                case '*':st.push(val2*val1);break;
                case '/':st.push(val2/val1);break;
            }
        }
    }
    return st.top();
}

int main() {
    string exprsn = "+9*26";
    cout << evaluatePrefix(exprsn) << endl;
    return 0;
}

