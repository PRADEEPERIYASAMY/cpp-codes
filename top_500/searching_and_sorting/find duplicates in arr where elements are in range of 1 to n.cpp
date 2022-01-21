using namespace std;
#include <bits/stdc++.h>
#define end "\n"
#define space " "

int main(){
    int numRay[] = { 0, 4, 3, 2, 7, 8, 2, 3, 1 };
    int arr_size = sizeof(numRay) / sizeof(numRay[0]);
    for (int i = 0; i < arr_size; i++) numRay[numRay[i]%arr_size]+=arr_size;
    for (int i = 0; i < arr_size; i++) if(numRay[i]>=arr_size*2)cout<<i<<space;
    return 0;
}

