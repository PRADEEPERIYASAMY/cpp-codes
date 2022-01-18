using namespace std;
#include <bits/stdc++.h>

void segregate0and1(int arr[],int n){
    int count = 0;
    for (int i = 0; i < n; i++) {
        if(arr[i] == 0){
            swap(arr[i],arr[count]);
            count++;
        }
    }
}

int main(){
    int arr[] = {0, 1, 0, 1, 1, 1}; 
    int i, arr_size = sizeof(arr)/sizeof(arr[0]); 
    segregate0and1(arr, arr_size); 
    cout << "Array after segregation "; 
    for (i = 0; i < 6; i++) cout << arr[i] << " "; 
    return 0;
}

