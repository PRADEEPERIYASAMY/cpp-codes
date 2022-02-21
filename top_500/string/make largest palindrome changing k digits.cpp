#include <bits/stdc++.h>
using namespace std;

string maximumPalinUsingKChanges(string str, int k){
    string plain = str;
    int l = 0;
    int r = str.size()-1;
    while(l<r){
        if(str[l] != str[r]){
            plain[l] = plain[r] = max(str[l],str[r]);
            k--;
        }
        l++,r--;
    }
    if(k<0) return "Not possible";
    l = 0;
    r = str.size() -1;
    while(l<=r){
        if(l == r) if(k>0) plain[l] = '9';
        if(plain[l]<'9'){
            if(k>=2 && plain[l] == str[l] && plain[r] == str[r]){
                k-=2;
                plain[l] = plain[r] = '9';
            }else if(k>= 1 && (plain[l] != str[l] || plain[r] != str[r])){
                k--;
                plain[l] = plain[r] = '9';
            }
        }
        l++;
        r--;
    }
    return plain;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/make-largest-palindrome-changing-k-digits/
	string str = "43435";
    int k = 3;
    cout << maximumPalinUsingKChanges(str, k);
    return 0;
}

