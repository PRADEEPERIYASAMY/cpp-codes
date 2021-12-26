#include <iostream>
using namespace std;
#include <bits/stdc++.h>

#define N 4

void rotateMatrix(int arr[N][N]){
    for (int i = 0; i < N; i++) reverse(arr[i],arr[i]+N);
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            swap(arr[i][j],arr[j][i]);
        }
    }
}

void displayMatrix(int mat[N][N]){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) printf("%2d ", mat[i][j]);
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int mat[N][N] = {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 },
        { 13, 14, 15, 16 }
    };

    rotateMatrix(mat);
    displayMatrix(mat);
 
    return 0;
}

