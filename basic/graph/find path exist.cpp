#include <bits/stdc++.h> 
#define R 4
#define C 4
using namespace std; 

bool findPath(int M[R][C]){
    queue<pair<int,int>> q;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if(M[i][j] == 1){
                q.push({i,j});
                break;
            }
        }
    }
    
    while(!q.empty()){
        auto x = q.front();
        q.pop();
        int i = x.first;
        int j = x.second;
        
        // skipping out of bounderies
        if(i<0 || i>R || j<0  || j>C) continue;
        if(M[i][j] == 0) continue;
        if(M[i][j] == 2) return true;
        
        // make as wall after completion
        M[i][j] = 0;
        // pushing to queue u=(i,j+1),u=(i,j-1)
        //                 u=(i+1,j),u=(i-1,j)
        for (int k = -1; k <=1; k+=2) {
            q.push({i+k,j});
            q.push({i,j+k});
        }
    }
    
    return false;
}

int main() 
{ 
	int M[R][C] = { { 0, 3, 0, 1 },
                    { 3, 0, 3, 3 },
                    { 2, 3, 3, 3 },
                    { 0, 3, 3, 3 } };

    (findPath(M) == true) ? cout << "Yes"
                          : cout << "No" << endl;

    return 0;
} 

