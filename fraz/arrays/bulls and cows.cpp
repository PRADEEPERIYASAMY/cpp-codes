#include <bits/stdc++.h>
using namespace std;

// string getHint(string secret, string guess) {
//     vector<int> record(10,0);
//     int n = secret.size(),bulls = 0,cows = 0;
//     for (int i = 0; i < n; i++) {
//         if(secret[i] == guess[i]) bulls++;
//         else ++record[secret[i]-'0'];
//     }
//     for (int i = 0; i < n; i++) {
//         if(secret[i] != guess[i] && record[guess[i]-'0']>0){
//             cows++;
//             record[guess[i]-'0']--;
//         }
//     }
//     return to_string(bulls)+"A"+to_string(cows)+"B";
// }

string getHint(string secret, string guess) {
    vector<int> record(10,0);
    int n = secret.size(),bulls = 0,cows = 0;
    for (int i = 0; i < n; i++) {
        if(secret[i] == guess[i]) bulls++;
        else {
            if(record[secret[i]-'0']++<0)cows++;
            if(record[guess[i]-'0']-->0) cows++;
        }
    }
    return to_string(bulls)+"A"+to_string(cows)+"B";
}

int main() {
	// leetcode
	// https://leetcode.com/problems/bulls-and-cows/
    return 0;
}
