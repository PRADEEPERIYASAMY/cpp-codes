#include <bits/stdc++.h> 
using namespace std; 
#define R 3
#define C 5
bool isValid(int i,int j){
    return (i >= 0 && j >= 0 && i< R && j< C);
}

bool isdelim(pair<int,int> a){
    return a.first == -1 && a.second == -1;
}

bool checkAll(int arr[R][C]){
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if(arr[i][j] == 1) return true;
        }
    }
    return false;
}

int rotOranges(int arr[R][C]){
    queue<pair<int,int>> q;
    int ans = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if(arr[i][j] == 2) q.push({i,j});
        }
    }
    q.push({-1,-1});
    
    while(!q.empty()){
        bool flag = false; // to check first rotten to avoid repetitiveness
        while(!isdelim(q.front())){
            auto t = q.front();
            int x = t.first;
            int y = t.second;
            if(isValid(x+1,y) && arr[x+1][y] == 1){
                if(!flag){
                    ans++;
                    flag = true;
                }
                arr[x+1][y] = 2;
                q.push({x+1,y});
            }
            if(isValid(x-1,y) && arr[x-1][y] == 1){
                if(!flag){
                    ans++;
                    flag = true;
                }
                arr[x-1][y] = 2;
                q.push({x-1,y});
            }
            if(isValid(x,y+1) && arr[x][y+1] == 1){
                if(!flag){
                    ans++;
                    flag = true;
                }
                arr[x][y+1] = 2;
                q.push({x,y+1});
            }
            if(isValid(x,y-1) && arr[x][y-1] == 1){
                if(!flag){
                    ans++;
                    flag = true;
                }
                arr[x][y-1] = 2;
                q.push({x,y-1});
            }
            q.pop();
        }
        q.pop(); // pop deliminetor
        if(!q.empty())q.push({-1,-1});
    }
    return checkAll(arr)?-1:ans;
}
// using bfs
int main(){
    int arr[][C] = { {2, 1, 0, 2, 1},
                     {1, 0, 1, 2, 1},
                     {1, 0, 0, 2, 1}};
    int ans = rotOranges(arr);
    if (ans == -1) cout << "All oranges cannot rotn";
    else cout << "Time required for all oranges to rot => " << ans << endl;
    return 0;
}
 
