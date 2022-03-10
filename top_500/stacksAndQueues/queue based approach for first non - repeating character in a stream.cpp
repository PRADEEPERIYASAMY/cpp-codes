#include <bits/stdc++.h>
using namespace std;

void firstnonrepeating(string str){
    queue<char> q;
    int cahrCount[26] = {0};
    for (int i = 0; i <str.size(); i++) {
        q.push(str[i]);
        cahrCount[str[i]-'a']++;
        while(!q.empty()){
            if(cahrCount[q.front()-'a']>1) q.pop();
            else{
                cout<<q.front()<<" ";
                break;
            }
        }
        if(q.empty()) cout<<-1<<" ";
    }
    cout<<"\n";
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/queue-based-approach-for-first-non-repeating-character-in-a-stream/
    string str = "aabc";
    firstnonrepeating(str);
    return 0;
}
