#include <bits/stdc++.h>
using namespace std;

// recursive
// bool isSubsetSum(int arr[], int n, int sum){
//     if (sum == 0)return true;
//     if (n == 0) return false;
//     if (arr[n - 1] > sum) return isSubsetSum(arr, n - 1, sum);
//     return isSubsetSum(arr, n - 1, sum)|| isSubsetSum(arr, n - 1, sum - arr[n - 1]);
// }

//dp tabulation
bool isSubsetSum(int arr[],int n,int sum){
    bool temp[n+1][sum+1];
    for (int i = 0; i < n; i++) temp[i][0] = true;
    for (int i = 1; i < sum; i++) temp[0][i] = false;
    for (int i = 1; i <=n; i++) {
        for (int j = 0; j <=sum; j++) {
            if(j<arr[i-1]) temp[i][j] = temp[i-1][j];
            else{
                temp[i][j] = temp[i-1][j] || temp[i-1][j-arr[i-1]];
            }
        }
    }
    return temp[n][sum];
}

bool findPartiion(int arr[], int n){
    int sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    if (sum % 2 != 0) return false;
    return isSubsetSum(arr, n, sum / 2);
}
 
int main(){
    int arr[] = { 3, 1, 5, 9, 12 };
    int n = sizeof(arr) / sizeof(arr[0]);
    if (findPartiion(arr, n) == true) cout << "Can be divided into two subsets of equal sum";
    else cout << "Can not be divided into two subsets of equal sum";
    return 0;
}

