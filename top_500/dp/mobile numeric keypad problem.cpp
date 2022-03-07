#include <bits/stdc++.h>
using namespace std;

// recursive
// int row[] = {0,0,-1,0,1};
// int col[] = {0,-1,0,1,0};

// int getCountUtil(char keypad[][3],int i,int j,int n){
//     if(keypad == nullptr || n<= 0) return 0;
//     if(n == 1) return 1;
//     int totalCount = 0;
//     for (int k = 0; k < 5; k++) {
//         int r = i+row[k],c = j+col[k];
//         if(r < 0 || r> 3 || c< 0 || c>2 || keypad[r][c] == '*' || keypad[r][c] == '#') continue;
//         totalCount+=getCountUtil(keypad,r,c,n-1);
//     }
//     return totalCount;
// }

// int getCount(char keypad[][3],int n){
//     if(keypad == nullptr || n<= 0) return 0;
//     if(n==1) return 10;
//     int totalCount = 0;
//     for (int i = 0; i < 4; i++) for (int j = 0; j < 3; j++) if(keypad[i][j] != '*' && keypad[i][j] != '#') totalCount+=getCountUtil(keypad,i,j,n);
//     return totalCount;
// }

// dynamic programming
int getCount(char keypad[][3],int n){
    if(keypad == nullptr || n<= 0) return 0;
    if(n == 1) return 10;
    int row[] = {0,0,-1,0,1};
    int col[] = {0,-1,0,1,0};
    int dp[10][n+1];
    int totalCount = 0, nextNum = 0;
    for (int i = 0; i <= 9; i++) dp[i][0] = 0,dp[i][1] = 1;
    for (int k = 2; k <= n; k++) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                if(keypad[i][j] != '*' && keypad[i][j] != '#'){
                    int num = keypad[i][j] - '0';
                    dp[num][k] = 0;
                    for (int dir = 0; dir < 5; dir++) {
                        int r = i+row[dir],c = j+col[dir];
                        if(r<0 || r> 3 || c<0 || c>2 || keypad[r][c] == '*' || keypad[r][c] == '#') continue;
                        nextNum = keypad[r][c]-'0';
                        dp[num][k] +=dp[nextNum][k-1];
                    }
                }
            }
        }
    }
    totalCount = 0;
    for (int i = 0; i <= 9; i++) totalCount += dp[i][n];
    return totalCount;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/mobile-numeric-keypad-problem/ 
	char keypad[4][3] = {{'1','2','3'},
                        {'4','5','6'},
                        {'7','8','9'},
                        {'*','0','#'}};
    printf("Count for numbers of length %d: %dn", 1, getCount(keypad, 1));
    printf("Count for numbers of length %d: %dn", 2, getCount(keypad, 2));
    printf("Count for numbers of length %d: %dn", 3, getCount(keypad, 3));
    printf("Count for numbers of length %d: %dn", 4, getCount(keypad, 4));
    printf("Count for numbers of length %d: %dn", 5, getCount(keypad, 5));
    return 0;
}
