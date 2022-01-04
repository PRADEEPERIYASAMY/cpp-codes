#include<bits/stdc++.h>
using namespace std;

// recursive
// bool isSubsetSum(int arr[],int n,int sum){
//     if(sum == 0) return true;
//     if(n == 0) return false;
//     if(arr[n-1]>sum) return isSubsetSum(arr,n-1,sum);
//     return isSubsetSum(arr,n-1,sum) || isSubsetSum(arr,n-1,sum-arr[n-1]);
// }

// dp tabulation
// bool isSubsetSum(int arr[],int n,int sum){
//     bool temp[n+1][sum+1];
//     for (int i = 0; i < n; i++) temp[i][0] = true;
//     for (int i = 1; i < sum; i++) temp[0][i] = false;
//     for (int i = 1; i <=n; i++) {
//         for (int j = 0; j <=sum; j++) {
//             if(j<arr[i-1]) temp[i][j] = temp[i-1][j];
//             else{
//                 temp[i][j] = temp[i-1][j] || temp[i-1][j-arr[i-1]];
//             }
//         }
//     }
//     return temp[n][sum];
// }

// dp memorization
int tab[2000][2000];
bool isSubsetSum(int arr[],int n,int sum){
    if(sum == 0) return 1;
    if(n <= 0) return 0;
    if(tab[n-1][sum] != -1) return tab[n-1][sum];
    if(arr[n-1]>sum) return tab[n-1][sum] = isSubsetSum(arr,n-1,sum);
    else return tab[n-1][sum] = isSubsetSum(arr,n-1,sum) || isSubsetSum(arr,n-1,sum-arr[n-1]);
}

int main() {
    memset(tab, -1, sizeof(tab));
	int set[] = { 3, 34, 4, 12, 5, 2 };
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);
    if (isSubsetSum(set, n, sum) == true) cout <<"Found a subset with given sum";
    else cout <<"No subset with given sum";
    return 0;
}

