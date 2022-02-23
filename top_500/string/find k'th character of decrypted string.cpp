#include <bits/stdc++.h>
using namespace std;

char encodedChar(string str,int k){
    string expand = "";
    string temp;
    int freq = 0;
    for (int i = 0; str[i] != '\0';) {
        temp = "";
        freq = 0;
        while(islower(str[i])){
            temp.push_back(str[i]);
            i++;
        }
        while(isdigit(str[i])){
            freq = freq*10+str[i] - '0';
            i++;
        }
        for (int j = 1; j <= freq; j++) expand.append(temp);
    }
    if(freq == 0) expand.append(temp);
    return expand[k-1];
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/find-kth-character-of-decrypted-string/
    string str = "ab4c12ed3";
    int k = 21;
    cout << encodedChar(str, k) << endl;
    return 0;
}

