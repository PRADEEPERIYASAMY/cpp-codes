#include <iostream>
using namespace std;

int findMajority(int arr[],int n){
    int res = 0,count = 1;
    for (int i = 1; i < n; i++) {
        if(arr[i] == arr[res]) count++;
        else count--;
        
        if(count == 0){
            res = i;
            count = 1;
        }
    }
    
    count = 0;
    
    for (int i = 0; i < n; i++) if(arr[i] == arr[res]) count++;
    
    if(count <= n/2) return -1;
    return res;
}

int main() {
	int arr[] = {8, 8, 6, 6, 6, 4, 6}, n = 7;
    cout<<findMajority(arr, n);
	return 0;
}

