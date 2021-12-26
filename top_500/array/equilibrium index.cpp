#include <iostream>
using namespace std;

int equilibrium(int arr[],int n){
    int sum = 0,left = 0;
    for (int i = 0; i < n; i++) {
        sum+=arr[i];
    }
    
    for (int i = 0; i < n; i++) {
        sum -= arr[i];
        if(sum == left) return i;
        left+=arr[i];
    }
    
    return -1;
}

int main()
{
    int arr[] = { -7, 1, 5, 2, -4, 3, 0 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    cout << "First equilibrium index is " << equilibrium(arr, arr_size);
    return 0;
}

