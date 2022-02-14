vector<string> fullJustify(vector<string>& words, int maxWidth) {
    int n = words.size();
    vector<string> res;
    int word_num;
    for (int start = 0; start < n ; start+=word_num) {
        int curWidth = 0;
        for(word_num = 0;start+word_num<n && curWidth+words[start+word_num].size()<= maxWidth - word_num;word_num++){
            curWidth+=words[start+word_num].size();
        }
        string cur = words[start];
        for(int interval = 0;interval<word_num-1;interval++){
            if(start+word_num == n) cur+=" ";
            else{
                int space = (maxWidth - curWidth)/(word_num-1);
                int extra = (maxWidth - curWidth)%(word_num-1);
                cur+=string(space+(extra>interval),' ');
            }
            cur+=words[start+interval+1];
        }
        cur+=string(maxWidth - cur.size(),' ');
        res.push_back(cur);
    }
    return res;
}

