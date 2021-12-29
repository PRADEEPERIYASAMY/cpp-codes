#include <iostream>
using namespace std;

bool checkEquilibrium(int arr[],int n){
    int sum = 0,lSum = 0;
    for (int i = 0; i < n; i++) sum+=arr[i];
    for (int i = 0; i < n; i++) {
        if(sum- arr[i] == lSum) return true;
        lSum+=arr[i];
        sum- arr[i];
    }
    return false;
}

int main() {
	int arr[] = {3, 4, 8, -9, 20, 6}, n = 6;
    printf("%s",checkEquilibrium(arr, n)? "true" : "false");
    return 0;
}

