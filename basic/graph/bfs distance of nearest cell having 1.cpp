#include <bits/stdc++.h> 
using namespace std; 
#define MAX 500
#define N 3
#define M 4

class graph
{
private:
    vector<int> g[MAX];
    int n,m;

public:
    graph(int a, int b){
        n = a;
        m = b;
    }

    void createGraph(){
        int k = 1;

        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if (i == n){
                    if (j != m){
                        g[k].push_back(k+1);
                        g[k+1].push_back(k);
                    }
                }

                else if (j == m){
                    g[k].push_back(k+m);
                    g[k+m].push_back(k);
                }
                else{
                    g[k].push_back(k+1);
                    g[k+1].push_back(k);
                    g[k].push_back(k+m);
                    g[k+m].push_back(k);
                }

                k++;
            }
        }
    }

    void bfs(bool visit[], int dist[], queue<int> q){
        while (!q.empty()){
            int temp = q.front();
            q.pop();

            for (int i = 0; i < g[temp].size(); i++)
            {
                if (visit[g[temp][i]] != 1)
                {
                    dist[g[temp][i]] =
                    min(dist[g[temp][i]], dist[temp]+1);

                    q.push(g[temp][i]);
                    visit[g[temp][i]] = 1;
                }
            }
        }
    }

    void print(int dist[]){
        for (int i = 1, c = 1; i <= n*m; i++, c++){
            cout << dist[i] << " ";
            if (c%m == 0)
                cout << endl;
        }
    }
};

void findMinDistance(bool mat[N][M]){
    graph g1(N, M);
    g1.createGraph();
    int dist[MAX];
    bool visit[MAX] = { 0 };
    for (int i = 1; i <= M*N; i++){
        dist[i] = INT_MAX;
        visit[i] = 0;
    }

    int k = 1;
    queue<int> q;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (mat[i][j] == 1)
            {
                dist[k] = 0;
                visit[k] = 1;
                q.push(k);
            }
            k++;
        }
    }
    g1.bfs(visit, dist, q);
    g1.print(dist);
}

int main()
{
    bool mat[N][M] =
    {
        0, 0, 0, 1,
        0, 0, 1, 1,
        0, 1, 1, 0
    };

    findMinDistance(mat);

    return 0;
}

