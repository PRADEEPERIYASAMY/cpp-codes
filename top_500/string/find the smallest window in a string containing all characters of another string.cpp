#include <bits/stdc++.h>
using namespace std;

const int noOfChars = 256;

string findSubString(string str,string pat){
    int len1 = str.size();
    int len2 = pat.size();
    if(len1 < len2){
        cout<<"No such window exist ";
        return "";
    }
    int hashPat[noOfChars] = {0};
    int hashStr[noOfChars] = {0};
    for (int i = 0; i < len2; i++) hashPat[pat[i]]++;
    int start = 0,startIndex = -1,minLen = INT_MAX;
    int count = 0;
    for (int i = 0; i < len1; i++) {
        hashStr[str[i]]++;
        if(hashStr[str[i]]<=hashPat[str[i]])count++;
        if(count == len2){
            while(hashStr[str[start]]>hashPat[str[start]] || hashPat[str[start]] == 0){
                if(hashStr[str[start]]>hashPat[str[start]]) hashStr[str[start]]--;
                start++;
            }
            int lenWindow = i - start + 1;
            if(minLen>lenWindow){
                minLen = lenWindow;
                startIndex = start;
            }
        }
    }
    if(startIndex == -1){
        cout<<"no such window exists";
        return "";
    }
    return str.substr(startIndex,minLen);
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/find-the-smallest-window-in-a-string-containing-all-characters-of-another-string/
	string str = "this is a test string";
    string pat = "tist";
    cout << "Smallest window is : \n"<< findSubString(str, pat);
    return 0;
}

