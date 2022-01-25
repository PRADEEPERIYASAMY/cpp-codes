using namespace std;
#include <bits/stdc++.h>

void helper(string &digits,vector<string> &letters,vector<string> &res,string cur,int idx){
    if(idx == digits.size()){
        res.push_back(cur);return;
    }
    string l = letters[digits[idx]-'0'];
    for (int i = 0; i < l.size(); i++) helper(digits,letters,res,cur+l[i],idx+1);
}

vector<string> letterCombinations(string digits) { 
    vector<string> res;
    if(digits.empty()) return res;
    vector<string> letters = {"","","abc","def","ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string cur = "";
    helper(digits,letters,res,cur,0);
    return res;
}

int main(){
    //leet code solutions
    //https://leetcode.com/problems/letter-combinations-of-a-phone-number/
    return 0;
}

