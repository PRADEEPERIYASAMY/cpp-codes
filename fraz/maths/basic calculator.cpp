#include <iostream>
using namespace std;

int calculate(string s) { 
    if(s.empty()) return 0;
    int n = s.size(),num = 0,res = 0,sign = 1;
    stack<int> st;
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if(isdigit(c)) num = num*10+(c - '0');
        else if(c == '+') {
            res+=sign*num;
            num = 0;
            sign = 1;
        }else if(c == '-'){
            res+=sign*num;
            num = 0;
            sign = -1;
        }else if(c == '('){
            st.push(res);
            st.push(sign);
            res = 0;
            sign = 1;
        }else if(c == ')'){
            res+=sign*num;
            num = 0;
            res*=st.top();st.pop();
            res+=st.top();st.pop();
        }
    }
    if(num) res+=sign*num;
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/basic-calculator/
	return 0;
}

