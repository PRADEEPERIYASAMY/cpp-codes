#include <bits/stdc++.h>
using namespace std;
#define MAX_CAHRS 26

bool isValid(int count[],int k){
    int val = 0;
    for (int i = 0; i < MAX_CAHRS; i++) {
        if(count[i]>0) val++;
    }
    return k>=val;
}

void kUniques(string s,int k){
    int u = 0;
    int n = s.size();
    int count[MAX_CAHRS];
    memset(count,0,sizeof(count));
    for (int i = 0; i <n ; i++) {
        if(count[s[i]-'a'] == 0) u++;
        count[s[i] - 'a']++;
    }
    if(u<k){
        cout<<"Not enough unique characters";
        return;
    }
    int currStart = 0,currEnd = 0;
    int maxWindowSize = 1,maxWindowStart = 0;
    memset(count,0,sizeof(count));
    count[s[0]-'a']++;
    for (int i = 1; i < n; i++) {
        count[s[i]-'a']++;
        currEnd++;
        while(!isValid(count,k)){
            count[s[currStart]-'a']--;
            currStart++;
        }
        if(currEnd - currStart+1>maxWindowSize){
            maxWindowSize = currEnd - currStart+1;
            maxWindowStart = currStart;
        }
    }
    cout<<"Max substring is: "<<s.substr(maxWindowStart,maxWindowSize)<<" with length "<<maxWindowSize<<endl;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/find-the-longest-substring-with-k-unique-characters-in-a-given-string/
	string s = "aabacbebebe";
    int k = 3;
    kUniques(s, k);
    return 0;
}

