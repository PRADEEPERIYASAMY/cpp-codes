#include <bits/stdc++.h>
using namespace std;

struct Cube{
    int h,w,d;
};

int compare (const void *a, const void * b){
    return ( (*(Cube *)b).d * (*(Cube *)b).w ) -( (*(Cube *)a).d * (*(Cube *)a).w );
}

// dp
int maxStackHeight(Cube arr[],int n){
    Cube rot[3*n];
    int index = 0;
    for (int i = 0; i < n; i++) {
        //original
        rot[index].h = arr[i].h;
        rot[index].d = max(arr[i].d, arr[i].w);
        rot[index].w = min(arr[i].d, arr[i].w);
        index++;
        // First rotation of box
        rot[index].h = arr[i].w;
        rot[index].d = max(arr[i].h, arr[i].d);
        rot[index].w = min(arr[i].h, arr[i].d);
        index++;
        // Second rotation of box
        rot[index].h = arr[i].d;
        rot[index].d = max(arr[i].h, arr[i].w);
        rot[index].w = min(arr[i].h, arr[i].w);
        index++;
    }
    n = 3*n;
    qsort(rot,n,sizeof(rot[0]),compare);
    int lis[n];
    lis[0] = rot[0].h;
    for (int i = 1; i <n; i++) {
        lis[i] = rot[i].h;
        for (int j = 0; j<i; j++) {
            if(rot[j].w > rot[i].w && rot[j].d > rot[i].d) lis[i] = max(lis[i],lis[j]+rot[i].h); // elements below stak i shoul be small unlike original lis
        }
    }
    return *max_element(lis,lis+n);
}

//  memorization can be done in similar to lis

// variation of lis
int main(){
    Cube arr[] = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} };
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("The maximum possible height of stack is %d\n",maxStackHeight (arr, n) );
    return 0;
}

