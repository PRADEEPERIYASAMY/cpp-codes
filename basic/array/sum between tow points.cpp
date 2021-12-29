#include <iostream>
using namespace std;

int getSum(int arr[],int n,int i,int j){
    int prefix[n];
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++) prefix[i] = prefix[i-1]+arr[i];
    if(i != 0) return prefix[j]- prefix[i-1];
    return prefix[j];
}

int main() {
	int arr[] = {2, 8, 3, 9, 6, 5, 4}, n = 7;
    cout<<getSum(arr,n, 1, 3)<<endl;
    cout<<getSum(arr,n, 0, 2)<<endl;
}

