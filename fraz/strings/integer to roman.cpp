#include <iostream>
using namespace std;

string intToRoman(int num) {
    vector<char> roman{'M','D','C','L','X','V','I'};
    vector<int> value{1000,500,100,50,10,5,1};
    string res;
    for (int i = 0; i < 7; i+=2) {
        int d = num/value[i];
        if(d<4)for (int j = 0; j < d; j++) res+=roman[i];
        else if(d == 4) res = res+roman[i]+roman[i-1];
        else if(d>4 && d<9){
            res+=roman[i-1];
            for (int j = 0; j < d-5; j++) res+=roman[i];
        }else if(d == 9) res = res+roman[i]+roman[i-2];
        num%=value[i];
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/integer-to-roman/
	return 0;
}

