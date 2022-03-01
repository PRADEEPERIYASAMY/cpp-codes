#include <bits/stdc++.h>
using namespace std;

bool isKPartitionPossibleRec(int arr[],int subsetSum[],bool taken[],int subset,int k,int n,int curIdx,int limitIdx){
    if(subsetSum[curIdx] == subset){
        if(curIdx == k-2) return true;
        return isKPartitionPossibleRec(arr,subsetSum,taken,subset,k,n,curIdx+1,n-1);
    }
    for (int i = limitIdx; i >= 0; i--) {
        if(taken[i]) continue;
        int tmp = subsetSum[curIdx]+arr[i];
        if(tmp<=subset){
            taken[i] = true;
            subsetSum[curIdx]+=arr[i];
            bool nxt = isKPartitionPossibleRec(arr,subsetSum,taken,subset,k,n,curIdx,i-1);
            taken[i] = false;
            subsetSum[curIdx]-=arr[i];
            if(nxt) return true;
        }
    }
    return false;
}

bool isKPartitionPossible(int arr[],int N,int K){
    if(K == 1) return true;
    if(N<K) return false;
    int sum = 0;
    for (int i = 0; i < N; i++) sum+=arr[i];
    if(sum%K != 0) return false;
    int subset = sum/K;
    int subsetSum[K];
    bool taken[N];
    memset(subsetSum,0,sizeof(subsetSum));
    memset(taken,false,sizeof(taken));
    subsetSum[0] = arr[N-1];
    taken[N-1] = true;
    return isKPartitionPossibleRec(arr,subsetSum,taken,subset,K,N,0,N-1);
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/partition-set-k-subsets-equal-sum/
	int arr[] = {2, 1, 4, 5, 3, 3};
    int N = sizeof(arr) / sizeof(arr[0]);
    int K = 3;
 
    if (isKPartitionPossible(arr, N, K))cout << "Partitions into equal sum is possible.\n";
    else cout << "Partitions into equal sum is not possible.\n";
	return 0;
}

