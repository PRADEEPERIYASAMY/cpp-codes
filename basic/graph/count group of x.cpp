#include <bits/stdc++.h> 
using namespace std; 

void floodFill(vector<char> arr[],int v,int i,int j){
    if(i<0 || i>= v || j<0 || j>= v) return;
    if(arr[i][j] != 'X') return;
    arr[i][j] = 'O';
    floodFill(arr,v,i+1,j);
    floodFill(arr,v,i-1,j);
    floodFill(arr,v,i,j+1);
    floodFill(arr,v,i,j-1);
}

int countX(vector<char> arr[],int v){
    int count = 0;
    for (int i = 0; i < v; i++) {
        for (int j=0;j<v;j++) {
            if(arr[i][j] == 'X'){
                count++;
                floodFill(arr,v,i,j);
            }
        }
    }
    return count;
}

int main(){
    vector<char> arr[3];
    arr[0].push_back('X');
    arr[0].push_back('O');
    arr[0].push_back('X');
    arr[1].push_back('O');
    arr[1].push_back('X');
    arr[1].push_back('O');
    arr[2].push_back('X');
    arr[2].push_back('X');
    arr[2].push_back('X');
    cout<<countX(arr,3);
    return 0;
}

