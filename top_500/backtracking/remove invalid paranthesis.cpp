using namespace std;
#include <bits/stdc++.h>

bool isParanthesis(char c){
    return c == '(' || c == ')';
}

bool isValidString(string str){
    int count = 0;
    for (auto &i : str) {
        if(i == '(') count++;
        else if(i == ')') count--;
        if(count<0) return false;
    }
    return count == 0;
}

void removeInvalidParenthesis(string str){
    if(str.empty()) return;
    set<string> visit;
    queue<string> q;
    q.push(str);
    visit.insert(str);
    
    bool level = false;
    string temp;
    
    while(!q.empty()){
        str = q.front();q.pop();
        if(isValidString(str)){
            cout<<str<<endl;
            level = true;
        }
        if(level) continue;
        for (int i = 0; i < str.size(); i++) {
            if(!isParanthesis(str[i])) continue;
            temp = str.substr(0,i)+str.substr(i+1);
            if(visit.find(temp) == visit.end()){
                q.push(temp);
                visit.insert(temp);
            }
        }
    }
}

int main(){
    string expression = "()())()";
    removeInvalidParenthesis(expression);
    expression = "()v)";
    removeInvalidParenthesis(expression);
    return 0;
}

