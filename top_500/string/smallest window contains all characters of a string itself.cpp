#include <bits/stdc++.h>
using namespace std;
#define MAX_CHARS 256

string findSubString(string str){
    int n = str.size();
    if(n<= 1) return str;
    int distCount = 0;
    bool visited[MAX_CHARS] = {false};
    for (int i = 0; i < n; i++) {
        if(!visited[str[i]]){
            visited[str[i]] = true;
            distCount++;
        }
    }
    int start = 0,start_index = -1,minLen = INT_MAX;
    int count = 0;
    int currCount[MAX_CHARS] = {0};
    for (int i = 0; i < n; i++) {
        currCount[str[i]]++;
        if(currCount[str[i]] == 1) count++;
        if(count == distCount){
            while(currCount[str[start]]>1){
                if(currCount[str[start]]>1) currCount[str[start]]--;
                start++;
            }
            int len = i - start+1;
            if(minLen>len){
                minLen = len;
                start_index = start;
            }
        }
    }
    return str.substr(start_index,minLen);
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/smallest-window-contains-characters-string/
	string str = "aabcbcdbca";
    cout << "Smallest window containing all distinct characters is: "<< findSubString(str);
    return 0;
}

