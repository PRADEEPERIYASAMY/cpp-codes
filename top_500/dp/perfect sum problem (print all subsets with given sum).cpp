#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

void display(vector<int> &v){
    for (int i = 0; i < v.size(); i++) printf("%d ",v[i]);
    printf("\n");
}

void printSubsetsRec(int arr[],int i,int sum,vector<int> &p){
    if(i == 0 && sum != 0 && dp[0][sum]){
        p.push_back(arr[i]);
        if(arr[i] == sum) display(p);
        return;
    }
    if(i == 0 && sum == 0){
        display(p);
        return;
    }
    if(dp[i-1][sum]){
        vector<int> b = p;
        printSubsetsRec(arr,i-1,sum,b);
    }
    if(sum>=arr[i] && dp[i-1][sum - arr[i]]){
        p.push_back(arr[i]);
        printSubsetsRec(arr,i-1,sum - arr[i],p);
    }
}

void printAllSubsets(int arr[],int n,int sum){
    if(n == 0 || sum<0) return;
    dp = vector<vector<int>>(n,vector<int>(sum+1,false));
    for (int i = 0; i < n; i++) dp[i][0] = true;
    if(arr[0]<=sum) dp[0][arr[0]] = true;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= sum; j++) {
            dp[i][j] = (arr[i]<=j)?dp[i-1][j] || dp[i-1][j - arr[i]]: dp[i-1][j];
        }
    }
    if(dp[n-1][sum] == false) {
        printf("There is no subsets with sum %d\n",sum);
        return;
    }
    vector<int> p;
    printSubsetsRec(arr,n-1,sum,p);
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/perfect-sum-problem-print-subsets-given-sum/
	int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 10;
    printAllSubsets(arr, n, sum);
    return 0;
}
