#include <bits/stdc++.h>
using namespace std;

// int countDecodings(string digits,int n){
//     if(n == 0 || n == 1) return 1;
//     if(digits[0] == '0') return 0;
//     int count = 0;
//     if(digits[n-1]>'0') count = countDecodings(digits,n-1);
//     if(digits[n-2] == '1' || (digits[n-2] == '2' && digits[n-1] < '7')) count+=countDecodings(digits,n-2);
//     return count;
// }

// int countWays(string str){
//     if(str.size() == 0 || (str.size() == 1 && str[0] == '0')) return 0;
//     return countDecodings(str,str.size());
// }

// dp 
int countWays(string digits){
    int n = digits.size();
    int count[n+1];
    count[0] = 1,count[1] = 1;
    if(digits[0] == '0') return 0;
    for (int i = 2; i <= n; i++) {
        count[i] = 0;
        if(digits[i-1]>'0') count[i] = count[i-1];
        if(digits[i-2] == '1' ||(digits[i-2] == '2' && digits[i-1]<'7')) count[i]+=count[i-2];
    }
    return count[n];
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/count-possible-decodings-given-digit-sequence/
	string digits = "1234";
    cout << "Count is " << countWays(digits);
    return 0;
    return 0;
}
