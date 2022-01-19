using namespace std;
#include <bits/stdc++.h>

int win[8][3] = {{0, 1, 2},{3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};

bool isWin(char board[9],char c){
    for (int i = 0; i < 8; i++) if(board[win[i][0]] == c && board[win[i][1]] == c && board[win[i][2]] == c) return true;
    return false;
}

bool isValid(char board[9]){
    int x = 0,y=0;
    for (int i = 0; i < 9; i++) {
        if(board[i] == 'X') x++;
        if(board[i] == 'O') y++;
    }
    if(x == y || x == y+1){
        if(isWin(board,'O')){
            if(isWin(board,'X')) return false;
            return x == y;
        }
        if(isWin(board,'X') && x!= y+1) return false;
        return true;
    }
    return false;
}

int main(){
    char board[] = {'X', 'X', 'O',
                'O', 'O', 'X',
                'X', 'O', 'X'};
    (isValid(board))? cout << "Given board is valid":cout << "Given board is not valid";
    return 0;
}

