#include <bits/stdc++.h>
using namespace std;

int crossProduct(vector<int> &A,vector<int> &B,vector<int> &C){
    int ABx = B[0] - A[0];
    int ABy = B[1] - A[1];
    int BCx = C[0] - B[0];
    int BCy = C[1] - B[1];
    return ABx*BCy - ABy*BCx;
}

int dist(vector<int> &A,vector<int> B){
    return (B[0] - A[0])*(B[0] - A[0])+(B[1]-A[1])*(B[1] - A[1]);
}

int bottomLeftIdx(vector<vector<int>> &points){
    int idx = 0;
    for (int i = 1; i < points.size(); i++) {
        if(points[i][1]<points[idx][1] || (points[i][1] == points[idx][1] && points[i][0]>points[idx][0])) idx = i;
    }
    return idx;
}

bool check(vector<vector<int>> &res,vector<int> &p){
    for (auto r : res) {
        if(r[0] == p[0] && r[1] == p[1]) return false;
    }
    return true;
}

vector<vector<int>> outerTrees(vector<vector<int>>& points) {
    int n = points.size();
    vector<vector<int>> res;
    res.reserve(n);
    int firstIdx = bottomLeftIdx(points);
    vector<int> first = points[firstIdx];
    res.push_back(first);
    int curIdx = firstIdx;
    vector<int> cur = points[curIdx];
    while(true){
        vector<int> nex = points[0];
        int nexIdx = 0;
        for (int i = 1; i < n; i++) {
            if(i == curIdx) continue;
            int cross = crossProduct(cur,points[i],nex);
            if(nexIdx == curIdx || cross >0 || (cross == 0 && dist(points[i],cur) > dist(nex,cur))){
                nex = points[i];
                nexIdx = i;
            }
        }
        for (int i = 0; i < n; i++) {
            if(i == curIdx) continue;
            int cross = crossProduct(cur,points[i],nex);
            if(cross == 0) if(check(res,points[i])) res.push_back(points[i]);
        }
        cur = nex;
        curIdx = nexIdx;
        if(curIdx == firstIdx) break;
    }
    res.resize(res.size());
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/erect-the-fence/
	// https://leetcode.com/problems/erect-the-fence/discuss/1442266/A-Detailed-Explanation-with-Diagrams-(Graham-Scan)
    return 0;
}
