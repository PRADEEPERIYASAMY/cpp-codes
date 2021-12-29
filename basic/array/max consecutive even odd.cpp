#include <iostream>
using namespace std;

int maxEvenOdd(int arr[],int n){
    int cur = 1,m = 1;
    for (int i = 1; i < n; i++) {
        
        if( (arr[i]%2 == 0 && arr[i-1]%2 == 1) || (arr[i]%2 == 1 && arr[i-1]%2 == 0)){
            cur++;
            m = max(m,cur);
        }else{
            cur = 1;
        }
        
    }
    
    return m;
}

int main() {
	int arr[] = {5, 10, 20, 6, 3, 8}, n = 6;
    cout<<maxEvenOdd(arr, n);
	return 0;
}

