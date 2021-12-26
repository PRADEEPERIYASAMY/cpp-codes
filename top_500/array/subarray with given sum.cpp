#include <iostream>
using namespace std;

void subArraySum(int arr[],int n, int sum){
    int curSum = arr[0],start = 0;
    
    for (int i = 1; i <= n; i++) {
        
        while(curSum>sum && start<i-1){
            curSum-=arr[start];
            start++;
        }
        
        if(curSum == sum){
            cout<<start<<" "<<i-1;
            break;
        }
        
        if(i < n) curSum+=arr[i];
    }
}

int main()
{
    int arr[] = { 15, 2, 4, 8, 9, 5, 10, 23 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 23;
    subArraySum(arr, n, sum);
    return 0;
}

