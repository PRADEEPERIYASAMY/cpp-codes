using namespace std;
#include <bits/stdc++.h>

void rearrange(int arr[],int n){
    int max_i = n-1,min_i = 0,max_element = arr[n-1]+1;
    for (int i = 0; i < n; i++){
        if(i%2 == 0) {
            arr[i] += (arr[max_i]%max_element)*max_element;
            max_i--;
        }else{
            arr[i] += (arr[min_i]%max_element)*max_element;
            min_i++;
        }
    }
    for (int i = 0; i < n; i++) arr[i] /=max_element;
}

int main(){
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original Arrayn";
    for (int i = 0; i < n; i++)cout << arr[i] << " ";
    rearrange(arr, n);
    cout << "\nModified Array\n";
    for (int i = 0; i < n; i++)cout << arr[i] << " ";
    return 0;
}

