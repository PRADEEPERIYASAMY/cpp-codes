#include <bits/stdc++.h>
using namespace std;

int maxLevel(int boxes[],int n){
    sort(boxes,boxes+n);
    int ans = 1;
    int prevWidth = boxes[0];
    int prevCount = 1;
    int curWidth = 0;
    int curCount = 0;
    for (int i = 1; i < n; i++) {
        curWidth+=boxes[i];
        curCount+=1;
        if(curWidth>prevWidth && curCount>prevCount){
            prevCount = curCount;
            prevWidth = curWidth;
            curCount = curWidth = 0;
            ans++;
        }
    }
    return ans;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/find-maximum-height-pyramid-from-the-given-array-of-objects/
	int boxes[] = {10, 20, 30, 50, 60, 70};
    int n = sizeof(boxes)/sizeof(boxes[0]);
    cout << maxLevel(boxes, n) << endl;
    return 0;
}

