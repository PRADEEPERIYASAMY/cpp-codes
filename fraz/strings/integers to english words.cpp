#include <iostream>
using namespace std;

string helper(int num){
    vector<string> tens{"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> ones{"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string res;
    int a = num/100,b = num%100,c = num%10;
    if(a>0) res +=ones[a]+" Hundred";
    if(b>0) res+=(res.empty()?"":" ")+(b<20?ones[b]:tens[b/10]+(c>0?" "+ones[c]:""));
    return res;
}

string numberToWords(int num) {
    vector<string> thousands{" Thousand"," Million", " Billion"};
    string res = helper(num%1000);
    for (int i = 0; i < 3; i++) {
        num/=1000;
        res = (num%1000)?(helper(num%1000)+thousands[i]+" "+res):res;
    }
    while(res.back() == ' ') res.pop_back();
    return res.empty()?"Zero": res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/integer-to-english-words/
	return 0;
}

