#include <iostream>
using namespace std;

bool isNumber(string s) {
    bool num = false,numAfterE = true,sign = false,dot = false,exp = false;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if(s[i] == ' '){
            if(i+1<n && s[i+1] != ' ' && (num || sign || dot || exp)) return false;
        }else if(s[i] == '+' || s[i] == '-'){
            if(i>0 && s[i-1]!= ' ' && s[i-1] != 'e' && s[i-1] != 'E') return false;
            sign = true;
        }else if(s[i]>='0' && s[i]<= '9'){
            num = true;
            numAfterE = true;
        }else if(s[i] == '.') {
            if(dot || exp) return false;
            dot = true;
        }else if(s[i] == 'e' || s[i] == 'E'){
            if(!num || exp) return false;
            exp = true;
            numAfterE = false;
        }else return false;
    }
    return num && numAfterE;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/valid-number/
	return 0;
}

