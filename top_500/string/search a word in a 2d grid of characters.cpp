#include <bits/stdc++.h>
using namespace std;

int x[] = {-1,-1,-1,0,0,1,1,1};
int y[] = {-1,0,1,-1,1,-1,0,1};

bool search2d(vector<string> &grid,int row,int col,string word,int r,int c){
    if(grid[row][col] != word[0]) return false;
    int len = word.size();
    for (int dir = 0; dir < 8; dir++) {
        int k, rd = row+x[dir],cd = col+y[dir];
        for (k = 1; k < len; k++) {
            if(rd>=r || rd<0 || cd>=c || cd<0) break;
            if(grid[rd][cd] != word[k]) break;
            rd+=x[dir],cd +=y[dir];
        }
        if(k == len) return true;
    }
    return false;
}

void patterSearch(vector<string> &grid,string word,int r,int c){
    for (int row = 0; row < r; row++) {
        for (int col = 0; col < c; col++) {
            if(search2d(grid,row,col,word,r,c)) cout<<"pattern found at"<<row<<","<<col<<"\n";
        }
    }
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/search-a-word-in-a-2d-grid-of-characters/
	int r = 3,c = 13;
	vector<string> grid = { "GEEKSFORGEEKS",
                        "GEEKSQUIZGEEK",
                        "IDEQAPRACTICE" };
    patterSearch(grid,"GEEKS",r,c);
    return 0;
}

