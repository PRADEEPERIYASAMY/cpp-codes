#include <bits/stdc++.h>
using namespace std;

int patternCount(string str){
    char last = str[0];
    int i = 1,counter = 0;
    while(i<str.size()){
        if(str[i] == '0' && last == '1'){
            while(str[i] == '0') i++;
            if(str[i] == '1') counter++;
        }
        last = str[i];
        i++;
    }
    return counter;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/find-patterns-101-given-string/
	string str = "1001ab010abc01001";
    cout << patternCount(str) << endl;
    return 0;
}

