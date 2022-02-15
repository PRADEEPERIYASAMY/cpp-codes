#include <iostream>
using namespace std;

string multiply(string num1, string num2) {
    int m = num1.size(),n = num2.size();
    string res(m+n,'0');
    for (int i = m-1; i >= 0; i--) {
        int carry = 0;
        for (int j = n-1; j >= 0; j--) {
            int sum = (res[i+j+1]-'0') + (num1[i] - '0')*(num2[j] - '0')+carry;
            res[i+j+1] = sum%10+'0';
            carry = sum/10;
        }
        res[i]+=carry;
    }
    int startPos = res.find_first_not_of("0");
    return startPos != string::npos?res.substr(startPos):"0";
}

int main() {
	// leetcode
	// https://leetcode.com/problems/multiply-strings/
	return 0;
}

