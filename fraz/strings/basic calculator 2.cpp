#include <iostream>
using namespace std;

// with stack
// int calculate(string s) {
//     if(s.empty()) return 0;
//     int n = s.size(),res = 0,num = 0;
//     char op = '+';
//     stack<int> st;
//     for (int i = 0; i < n; i++) {
//         char c = s[i];
//         if(isdigit(c)) num = num*10+(c-'0');
//         if(c == '+' || c == '*' || c == '-' || c == '/' || i == n-1){
//             if(op == '+') st.push(num);
//             else if(op == '-') st.push(-num);
//             else if(op == '*' || op == '/') {
//                 int tmp = op == '*' ? st.top()*num:st.top()/num;
//                 st.pop();
//                 st.push(tmp);
//             }
//             op = c;
//             num = 0;
//         }
//     }
//     while(!st.empty()){
//         res+=st.top();
//         st.pop();
//     }
//     return res;
// }

int calculate(string s){
    if(s.empty()) return 0;
    int res = 0,cures = 0,num = 0,n = s.size();
    char op = '+';
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if(isdigit(c)) num = num*10+(c-'0');
        if(c == '+' || c == '-' || c == '*' || c == '/' || i == n-1){
            switch(op){
                case '+': cures+=num;break;
                case '-': cures-=num;break;
                case '*': cures*=num;break;
                case '/': cures/=num;break;
            }
            if(c == '+' || c == '-' || i == n-1){
                res+=cures;
                cures = 0;
            }
            op = c;
            num = 0;
        }
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/basic-calculator-ii/
	return 0;
}

