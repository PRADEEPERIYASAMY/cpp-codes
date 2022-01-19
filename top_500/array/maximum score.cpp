using namespace std;
#include <bits/stdc++.h>
#define N 3

void maxsc(int arr[N][N]){
    int e[N];
    e[N-1] = *max_element(arr[N-1],arr[N-1]+N);
    int sum = e[N-1];
    for (int i = N-2; i >= 0; i--) {
        e[i] = 0;
        for (int j = 0; j < N; j++) if(arr[i][j]<e[i+1]) e[i] = max(e[i],arr[i][j]);
        if(e[i] == 0){
            cout<<-1;
            return;
        }
        sum+=e[i];
    }
    cout<<sum;
}

int main(){
    int arr[N][N] = {1,2,3,4,5,6,7,8,9};
    maxsc(arr);
}

