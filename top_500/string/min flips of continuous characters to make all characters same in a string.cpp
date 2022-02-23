#include <bits/stdc++.h>
using namespace std;

int findFlips(string str,int n){
    char last = ' ';
    int res = 0;
    for (int i = 0; i < n; i++) {
        if(last != str[i]) res++;
        last = str[i];
    }
    return res/2;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/min-flips-of-continuous-characters-to-make-all-characters-same-in-a-string/
    string str = "00011110001110";
    int n = str.size();
    cout << findFlips(str, n);
}

