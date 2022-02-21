#include <bits/stdc++.h>
using namespace std;

int isOk(int oddCnt,int n){
    if(oddCnt>1) return false;
    if(oddCnt == 1 && n%2 == 0) return false;
    if(oddCnt == 0 && n%2 == 1) return false;
    return true;
}

void print(vector<int> v){
    for (int i = 0; i < v.size(); i++) {
        cout<<v[i]+1;
        if(i+1 <v.size()) cout<<" ";
    }
    cout<<endl;
}

int main() {
	// pepcoding
	// https://s3.amazonaws.com/codechef_shared/download/Solutions/FEB18/Setter/PERMPAL.cpp
	
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    vector<vector<int>> cnt(26);
	    for (int i = 0; i < s.size(); i++) cnt[s[i] - 'a'].push_back(i);
	    int oddCnt = 0;
	    int which = 0;
	    for (int i = 0; i < 26; i++) {
	        if(cnt[i].size()%2 == 1){
	            oddCnt++;
	            which = i;
	        }
	    }
	    int n = s.size();
	    if(!isOk(oddCnt,n)) cout<<"-1\n";
	    else {
	        vector<int> where(n);
	        if(oddCnt == 1){
	            where[n/2] = cnt[which].back();
	            cnt[which].pop_back();
	        }
	        int start = 0;
	        for (int i = 0; i < 26; i++) {
	            for (int j = 0; j < cnt[i].size(); j++) {
	                if(j%2 == 0) where[start] = cnt[i][j];
	                else{
	                    where[n - start - 1] = cnt[i][j];
	                    start++;
	                }
	            }
	        }
	        vector<int> answer(n);
	        for (int i = 0; i < n; i++) answer[where[i]] = i;
	        print(where);
	    }
	}
    return 0;
}

