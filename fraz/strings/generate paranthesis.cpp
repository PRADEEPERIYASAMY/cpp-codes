#include <iostream>
using namespace std;

void helper(vector<string> &res,string curr,int n,int m){
    if(n==0 && m==0){
        res.push_back(curr);
        return;
    }
    if(n>0) helper(res,curr+'(',n-1,m+1);
    if(m>0) helper(res,curr+')',n,m-1);
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    string curr;
    helper(res,curr,n,0);
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/generate-parentheses/
	return 0;
}

