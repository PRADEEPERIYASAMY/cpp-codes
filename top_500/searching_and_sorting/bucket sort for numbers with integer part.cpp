using namespace std;
#include <bits/stdc++.h>

void bucketSort(float arr[],int n,int nob){
    float max = *max_element(arr,arr+n);
    float min = *min_element(arr,arr+n);
    float range = (max - min)/nob;
    vector<float> b[nob];
    float diff = 0.0;int temp;
    for (int i = 0; i < n; i++) {
        diff = (arr[i]-min)/range;
        temp = (int) diff;
        diff-=temp;
        if(diff == 0 && arr[i] != min) b[temp-1].push_back(arr[i]);
        else b[temp].push_back(arr[i]);
    }
    for (int i = 0; i < nob; i++) sort(b[i].begin(),b[i].end());
    int index = 0;
    for (int i = 0; i < nob; i++) for (int j = 0; j < b[i].size(); j++) arr[index++] = b[i][j];
}
 
int main(){
    float arr[] = { 9.8, 0.6, 10.1, 1.9, 3.07, 3.04, 5.0, 8.0, 4.8, 7.68 };
    int n = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, n,5);
    cout << "Sorted array is \n";
    for (int i = 0; i < n; i++)cout << arr[i] << " ";
    return 0;
}

