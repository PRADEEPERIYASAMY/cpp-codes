using namespace std;
#include <bits/stdc++.h>
#define N 4

struct Mat{
    int element,i,next;
};

struct comp{
    bool operator()(Mat const &p1,Mat const &p2){
        return p1.element > p2.element;
    }
};

void printSorted(int mat[][N]){
    priority_queue<Mat,vector<Mat>,comp> pq;
    for (int i = 0; i < N; i++) pq.push({mat[i][0],i,1});
    while(!pq.empty()) {
        auto x = pq.top();
        cout<<x.element<<" ";
        pq.pop();
        if(x.next<N) pq.push({mat[x.i][x.next],x.i,x.next+1});
    }
}

int main(){
    int mat[N][N] = { {10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {27, 29, 37, 48},
                    {32, 33, 39, 50},
                  };
  printSorted(mat);
  return 0;
}

