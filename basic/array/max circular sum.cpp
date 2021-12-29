#include <iostream>
using namespace std;

int normalMaxSum(int arr[], int n){
    int cur = arr[0],m= cur;
    for (int i = 1; i < n; i++) {
        cur = max(cur+arr[i],arr[i]);
        m = max(m,cur);
    }
    return m;
}

int circularMaxSum(int arr[],int n){
    int normal = normalMaxSum(arr,n);
    if(normal<0) return normal;
    
    int arrSum = 0;
    
    for (int i = 0; i < n; i++) {
        arrSum+=arr[i];
        arr[i]=-arr[i];
    }
    
    return max(normal,arrSum+normalMaxSum(arr,n));
}

int main() {
    
	int arr[] = {8, -4, 3, -5, 4}, n = 5;
    cout<<circularMaxSum(arr, n);
	return 0;
}

