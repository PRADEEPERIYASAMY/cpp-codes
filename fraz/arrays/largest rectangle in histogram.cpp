#include <iostream>
using namespace std;

int largestRectangleArea(vector<int>& heights) { 
    int res = 0;
    stack<int> st;
    heights.push_back(0);
    for (int i = 0; i < heights.size(); i++) {
        while(!st.empty() && heights[st.top()]>=heights[i]){
            int cur = st.top();st.pop();
            res = max(res,heights[cur]*(st.empty()?i:i-st.top()-1));
        }
        st.push(i);
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/largest-rectangle-in-histogram/
	return 0;
}

