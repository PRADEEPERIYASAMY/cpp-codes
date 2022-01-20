using namespace std;
#include <bits/stdc++.h>

struct Point{int val,x,y;};

struct comp{bool operator()(Point const &pt1,Point const &pt2){return pt1.val > pt2.val;}};

int kthSmallest(int mat[4][4],int n,int k){
    priority_queue<Point,vector<Point>,comp> pq;
    for (int i = 0; i < n; i++) pq.push({mat[i][0],i,0});
    for (int i = 1; i < k; i++) {
        auto temp = pq.top();
        pq.pop();
        if(temp.y+1<n) pq.push({mat[temp.x][temp.y+1],temp.x,temp.y+1});
    }
    return mat[pq.top().x][pq.top().y];
}

int main(){
    int mat[4][4] = {
        { 10, 20, 30, 40 },
        { 15, 25, 35, 45 },
        { 25, 29, 37, 48 },
        { 32, 33, 39, 50 },
    };
    cout << "7th smallest element is "<< kthSmallest(mat, 4, 7);
    return 0;
}

