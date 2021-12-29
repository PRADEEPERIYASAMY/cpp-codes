#include <iostream>
using namespace std;

int maxSum(int arr[],int n){
    int cur = arr[0],m = arr[0];
    for (int i = 1; i < n; i++) {
        cur = max(cur+arr[i],arr[i]);
        m = max(m,cur);
    }
    
    return m;
}

int main() {
	int arr[] = {1, -2, 3, -1, 2}, n = 5;
    cout<<maxSum(arr, n);;
	return 0;
}

