#include <bits/stdc++.h>
using namespace std;
#define R 3
#define C 5

bool isvalid(int i,int j){
    return (i>=0 && j>=0 && i<R && j<C);
}

struct ele{
    int x,y;
};

bool isdelim(ele temp){
    return temp.x == -1 && temp.y == -1;
}

bool checkall(int arr[][C]){
    for (int i = 0; i <R; i++) {
        for (int j = 0; j <C; j++) {
            if(arr[i][j] == 1 ) return true;
        }
    }
    return false;
}

int rotOranges(int arr[][C]){
    queue<ele> Q;
    ele temp;
    int ans = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if(arr[i][j] == 2) Q.push({i,j});
        }
    }
    Q.push({-1,-1});
    while(!Q.empty()){
        bool flag = false;
        while(!isdelim(Q.front())){
            auto[x,y] = Q.front();Q.pop();
            if(isvalid(x+1,y) && arr[x+1][y] == 1){
                if(!flag) ans++,flag = true;
                arr[x+1][y] = 2;
                Q.push({x+1,y});
            }
            if(isvalid(x-1,y) && arr[x-1][y] == 1){
                if(!flag) ans++,flag = true;
                arr[x-1][y] = 2;
                Q.push({x-1,y});
            }
            if(isvalid(x,y+1) && arr[x][y+1] == 1){
                if(!flag) ans++,flag = true;
                arr[x][y+1] = 2;
                Q.push({x,y+1});
            }
            if(isvalid(x,y-1) && arr[x][y-1] == 1){
                if(!flag) ans++,flag = true;
                arr[x][y-1] = 2;
                Q.push({x,y-1});
            }
        }
        Q.pop();
        if(!Q.empty()) Q.push({-1,-1});
    }
    return (checkall(arr))?-1:ans;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/minimum-time-required-so-that-all-oranges-become-rotten/
	int arr[][C] = { {2, 1, 0, 2, 1},
                     {1, 0, 1, 2, 1},
                     {1, 0, 0, 2, 1}};
    int ans = rotOranges(arr);
    if (ans == -1) cout << "All oranges cannot rotn";
    else cout << "Time required for all oranges to rot => " << ans << endl;
    return 0;
}