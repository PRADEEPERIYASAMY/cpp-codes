using namespace std;
#include <bits/stdc++.h>

bool checkbit(int arr[],int index){
    return arr[index>>5]&(1<<(index&31));
}

bool setbit(int arr[],int index){
    return arr[index>>5] |= (1<<(index&31));
}

int main(){
    int a = 2, b = 10;
    int size = abs(b - a);
    size = ceil(size / 32);
    int* array = new int[size];
    for (int i = a; i <= b; i++)if (i % 2 == 0 || i % 5 == 0)setbit(array, i - a);
    cout << "MULTIPLES of 2 and 5:\n";
    for (int i = a; i <= b; i++)if (checkbit(array, i - a))cout << i << " ";
    return 0;
}

