#include <bits/stdc++.h>
using namespace std;

float findWater(int i,int j,float X){
    if(j>i){
        cout<<"Incorrect Input";
        return 0.0;
    }
    float glass[i*(i+1)/2] = {0.0};
    int index = 0;
    glass[index] = X;
    for (int row = 1; row <= i; row++) {
        for (int col = 1; col <= row; col++,index++) {
            X = glass[index];
            glass[index] = X>=1.0?1.0:X;
            X = (X>=1.0)?X-1:0.0;
            glass[index+row]+=X/2;
            glass[index+row+1]+=X/2;
        }
    }
    return glass[i*(i-1)/2+j-1];
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/find-water-in-a-glass/
	int i = 2, j = 2;
    float X = 2.0; 
    printf("Amount of water in jth glass of ith row is: %f",findWater(i, j, X));
    return 0;
}