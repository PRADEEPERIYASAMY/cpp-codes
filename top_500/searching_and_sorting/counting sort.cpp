using namespace std;
#include <bits/stdc++.h>
#define RANGE 255

void countSort(char arr[]){
    int n = strlen(arr);
    char output[n];
    int countRange[RANGE+1],i;
    memset(countRange,0,sizeof(countRange));
    for (int i = 0; i < n; i++) countRange[arr[i]]++;
    for (int i = 1; i <= RANGE; i++) countRange[i]+=countRange[i-1];
    for (int i = 0; i < n; i++) {
        output[countRange[arr[i]]-1] = arr[i];
        countRange[arr[i]]--;
    }
    for (int i = 0; i < n; i++) arr[i] = output[i];
}


int main(){
    char arr[] = "geeksforgeeks";
    countSort(arr);
    cout << "Sorted character array is " << arr;
    return 0;
}

