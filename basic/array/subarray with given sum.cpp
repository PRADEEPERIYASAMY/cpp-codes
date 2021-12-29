#include <iostream>
using namespace std;

void subArraySum(int arr[],int n,int sum){
    int cur = arr[0],start = 0,i;
    for (int i = 1; i < n; i++) {
        while(cur>sum && start<i-1){
            cur-=arr[start];
            start++;
        }
        
        if(cur == sum){
            cout<<"between "<<start<<" "<<i-1;
            return;
        }
        
        if(cur<sum) cur+=arr[i];
    }
    cout<<"not found";
    return;
}

int main() {
	int arr[] = {15, 2, 4, 8, 9, 5, 10, 23}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	int sum = 23; 
	subArraySum(arr, n, sum); 
	return 0;
}

