#include <bits/stdc++.h>
using namespace std;

// for single operands
// int evaluatePostfix(string str){
//     stack<int> st;
//     for (int i = 0; i <str.size(); i++) {
//         if(isdigit(str[i])) st.push(str[i]-'0');
//         else{
//             int val1 = st.top();st.pop();
//             int val2 = st.top();st.pop();
//             switch(str[i]){
//                 case '+': st.push(val2+val1);break;
//                 case '-': st.push(val2-val1);break;
//                 case '*': st.push(val2*val1);break;
//                 case '/': st.push(val2/val1);break;
//             }
//         }
//     }
//     return st.top();
// }

// more general version 
int evaluatePostfix(string str){
    stack<int> st;
    for (int i = 0; i < str.size(); i++) {
        if(str[i] == ' ') continue;
        else if(isdigit(str[i])){
            int num = 0;
            while(isdigit(str[i])){
                num = num*10+(int)(str[i]-'0');
                i++;
            }
            i--;
            st.push(num);
        }else{
            int val1 = st.top();st.pop();
            int val2 = st.top();st.pop();
            switch(str[i]){
                case '+': st.push(val2+val1);break;
                case '-': st.push(val2-val1);break;
                case '*': st.push(val2*val1);break;
                case '/': st.push(val2/val1);break;
            }
        }
    }
    return st.top();
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/stack-set-4-evaluation-postfix-expression/
    //string str = "231*+9-";
    string str = "100 200 + 2 / 5 * 7 +";
    cout<<"postfix evaluation: "<< evaluatePostfix(str);
    return 0;
}
