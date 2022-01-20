using namespace std;
#include <bits/stdc++.h>

int x[] = {-1,-1,-1,0,0,1,1,1};
int y[] = {-1,0,1,-1,1,-1,0,1};

bool search2D(vector<string> &grid,int row,int col,string word,int r,int c){
    if(grid[row][col] != word[0]) return false;
    int len = word.size();
    for (int i = 0; i < 8; i++) {
        int j,rd = row+x[i],cd = col+y[i];
        for (j = 1; j < len; j++) {
            if(rd>=r || rd<0 || cd>= c || cd<0) break;
            if(grid[rd][cd] != word[j]) break;
            rd+=x[i],cd+=y[i];
        }
        if(j == len) return true;
    }
    return false;
}

void patternSearch(vector<string> &grid,string word,int r,int c){
    for (int i = 0; i < r; i++)for (int j = 0; j < c; j++)if(search2D(grid,i,j,word,r,c))cout<<"found at"<<i<<" "<<j<<"\n";
}

int main(){
      int R = 3, C = 13;
    vector<string> grid = { "GEEKSFORGEEKS","GEEKSQUIZGEEK","IDEQAPRACTICE" };
    patternSearch(grid, "GEEKS", R, C);
    cout << endl;
    patternSearch(grid, "EEE", R, C);
    return 0;
}

