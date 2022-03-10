#include <bits/stdc++.h>
using namespace std;
#define N 8

bool MATRIX[N][N] = {{0, 0, 1, 0},
                    {0, 0, 1, 0},
                    {0, 0, 0, 0},
                    {0, 0, 1, 0}};

// using indegree and outdegree
// int findCelebrity(int n){
//     int indegree[n] = {0},outdegree[n] = {0};
//     for (int i = 0; i <n; i++) {
//         for (int j = 0; j <n; j++) {
//             int x = MATRIX[i][j];
//             outdegree[i]+=x;
//             indegree[j]+=x;
//         }
//     }
//     for (int i = 0; i < n; i++) if(indegree[i] == n-1 && outdegree[i] == 0) return i;
//     return -1;
// }

// using stack 
// int findCelebrity(int n){
//     stack<int> st;
//     int c;
//     for (int i = 0; i < n; i++) st.push(i);
//     while(st.size()>1){
//         int a = st.top();st.pop();
//         int b = st.top();st.pop();
//         if(MATRIX[a][b]) st.push(b);
//         else st.push(a);
//     }
//     if(st.empty()) return -1;
//     c = st.top();st.pop();
//     for (int i = 0; i < n; i++) {
//         if(i != c && (MATRIX[c][i] || !MATRIX[i][c])) return -1;
//     }
//     return c;
// }

int findCelebrity(int n){
    int i = 0,j = n-1;
    while(i<j){
        if(MATRIX[j][i] == 1) j--;
        else i++;
    }
    int candidate = i;
    for (i = 0; i < n; i++) {
        if(i != candidate && (MATRIX[i][candidate] == 0 || MATRIX[candidate][i] == 1)) return -1;
    }
    return candidate;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/the-celebrity-problem/
	int n = 4;
    int id = findCelebrity(n);
    id == -1 ? cout << "No celebrity" :cout << "Celebrity ID " << id;
    return 0;
}
