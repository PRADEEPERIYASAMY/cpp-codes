#include <bits/stdc++.h> 
#define R 4
#define C 4
using namespace std; 

void printLevels(vector<int> graph[],int V,int x){
    int level[V];
    bool marked[V];
    queue<int> q;
    q.push(x);
    level[x] = 0;
    marked[x] = true;
    while(!q.empty()){
        int n = q.front();
        q.pop();
        for (auto &i : graph[n]) {
            if(!marked[i]){
                q.push(i);
                level[i] = level[n]+1;
                marked[i] = true;
            }
        }
    }
    cout << "Nodes"<< "    "<< "Level" << endl;
    for (int i = 0; i < V; i++) cout << " " << i << "   -->   " << level[i] << endl;
}

int main() { 
	int V = 8;
    vector<int> graph[V];

    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(4);
    graph[1].push_back(5);
    graph[2].push_back(5);
    graph[2].push_back(6);
    graph[6].push_back(7);

    // call levels function with source as 0
    printLevels(graph, V, 0);

    return 0;
} 

