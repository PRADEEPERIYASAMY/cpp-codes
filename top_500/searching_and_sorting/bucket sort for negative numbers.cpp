using namespace std;
#include <bits/stdc++.h>

void bucketSort(vector<float> &arr,int n){
    vector<float> b[n];
    for (int i = 0; i < n; i++) {
        int b1 = n*arr[i];
        b[b1].push_back(arr[i]);
    }
    for (int i = 0; i < n; i++) sort(b[i].begin(),b[i].end());
    int index = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < b[i].size(); j++) arr[index++] = b[i][j];
}

void sortMixed(float arr[],int n){
    vector<float> neg,pos;
    for (int i = 0; i < n; i++) {
        if(arr[i]<0) neg.push_back(-1*arr[i]);
        else pos.push_back(arr[i]);
    }
    bucketSort(neg,neg.size());
    bucketSort(pos,pos.size());
    for (int i = 0; i < neg.size(); i++) arr[i] = -1*(neg[neg.size()-i-1]);
    for (int i = neg.size(); i < n; i++) arr[i-neg.size()]; 
}
 
int main(){
    float arr[] = {-0.897, 0.565, 0.656,-0.1234, 0, 0.3434};
    int n = sizeof(arr)/sizeof(arr[0]);
    sortMixed(arr, n);
    cout << "Sorted array is \n";
    for (int i=0; i<n; i++) cout << arr[i] << " ";
    return 0;
}

