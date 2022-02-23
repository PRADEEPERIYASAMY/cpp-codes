#include <bits/stdc++.h>
using namespace std;
#define NO_OF_CHARS 256

void printDistinct(string str){
    vector<int> count(NO_OF_CHARS,0);
    for (int i = 0; i < str.size(); i++)count[str[i]]++;
    for (int i = 0; i < str.size(); i++)if(count[str[i]] == 1)cout<<str[i];
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/print-all-distinct-characters-of-a-string-in-order-3-methods/
    string str = "GeeksforGeeks";
    printDistinct(str);
    return 0;
}

