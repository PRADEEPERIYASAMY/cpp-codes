#include <bits/stdc++.h>
using namespace std;

bool findDuplicateparenthesis(string str){
    stack<char> st;
    for (auto &ch : str) {
        if(ch == ')'){
            char top = st.top();st.pop();
            int elementsInside = 0;
            while(top != '('){
                elementsInside++;
                top = st.top();st.pop();
            }
            if(elementsInside<1) return true;
        } else st.push(ch);
    }
    return false;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/find-expression-duplicate-parenthesis-not/
	string str = "(((a+(b))+(c+d)))";
    if (findDuplicateparenthesis(str))cout << "Duplicate Found ";
    else cout << "No Duplicates Found ";
    return 0;
}