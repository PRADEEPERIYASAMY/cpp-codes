int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if(intervals.size()<=1) return 0;
    sort(intervals.begin(),intervals.end());
    int res = 0,minEnd = intervals[0][1];
    for (int i = 1; i < intervals.size(); i++) {
        if(minEnd<=intervals[i][0]) minEnd = intervals[i][1];
        else{
            minEnd = min(minEnd,intervals[i][1]);
            res++;
        }
    }
    return res;
}

