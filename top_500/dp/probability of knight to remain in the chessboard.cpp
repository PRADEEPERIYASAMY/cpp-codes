#include <bits/stdc++.h>
using namespace std;
#define N 8

int dx[] = {1,2,2,1,-1,-2,-2,-1};
int dy[] = {2,1,-1,-2,-2,-1,1,2};

bool inside(int x,int y){
    return (x>=0 and x<N and y>= 0 and y<N);
}

double findProb(int start_x,int start_y,int steps){
    double dp[N][N][steps+1];
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) dp[i][j][0] = 1;
    for (int s = 1; s <=steps; s++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                double prob = 0.0;
                for (int dir = 0; dir < 8; dir++) {
                    int x = i+dx[dir],y = j+dy[dir];
                    if(inside(x,y)) prob +=dp[x][y][s-1]/8.0l;
                }
                dp[i][j][s] = prob;
            }
        }
    }
    return dp[start_x][start_y][steps];
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/probability-knight-remain-chessboard/
	int K = 3;
    cout << findProb(0, 0, K) << endl;
    return 0;
}
