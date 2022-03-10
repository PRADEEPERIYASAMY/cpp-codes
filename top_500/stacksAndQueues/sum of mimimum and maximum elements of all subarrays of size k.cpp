#include <bits/stdc++.h>
using namespace std;

int SumOfKsubArray(int arr[],int n,int k){
    int sum = 0;
    deque<int> s(k),g(k);
    int i = 0;
    for (i = 0; i <k; i++) {
        while(!s.empty() && arr[s.back()]>= arr[i]) s.pop_back();
        while(!g.empty() && arr[g.back()]<=arr[i]) g.pop_back();
        g.push_back(i);
        s.push_back(i);
    }
    
    for (; i < n; i++) {
        sum += arr[s.front()]+arr[g.front()];
        while(!s.empty() && s.front() <= i-k) s.pop_front();
        while(!g.empty() && g.front() <= i-k) g.pop_front();
        while(!s.empty() && arr[s.back()]>=arr[i]) s.pop_back();
        while(!g.empty() && arr[g.back()]<=arr[i]) g.pop_back();
        g.push_back(i);
        s.push_back(i);
    }
    sum += arr[s.front()]+arr[g.front()];
    return sum;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/sum-minimum-maximum-elements-subarrays-size-k/
	int arr[] = {2, 5, -1, 7, -3, -1, -2} ;
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    cout << SumOfKsubArray(arr, n, k) ;
    return 0;
}