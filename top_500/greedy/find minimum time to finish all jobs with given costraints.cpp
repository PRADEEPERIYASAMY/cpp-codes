#include <bits/stdc++.h>
using namespace std;

bool isPossible(int time,int k,int job[],int n){
    int cnt = 1;
    int currTime = 0;
    for (int i = 0; i < n;) {
        if(currTime+job[i]>time){
            currTime = 0;
            cnt++;
        }else{
            currTime+=job[i];
            i++;
        }
    }
    return cnt<=k;
}

int findMinTime(int k,int t,int job[],int n){
    int end = 0,start = 0;
    for (int i = 0; i < n; i++) end+=job[i];
    int ans = end;
    int jobMax = *max_element(job,job+n);
    while(start<=end){
        int mid = (start+end)/2;
        if(mid>=jobMax && isPossible(mid,k,job,n)){
            ans = min(ans,mid);
            end = mid-1;
        }else start = mid+1;
    }
    return ans*t;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/find-minimum-time-to-finish-all-jobs-with-given-constraints/
	int job[] =  {10, 7, 8, 12, 6, 8};
    int n = sizeof(job)/sizeof(job[0]);
    int k = 4, T = 5;
    cout << findMinTime(k, T, job, n) << endl;
    return 0;
}

