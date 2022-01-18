using namespace std;
#include <bits/stdc++.h>

int solve(vector<int> &rooms,int target){
    if(rooms.empty()) return -1;
    for (int i = 0; i < rooms.size(); i++) if(rooms[i]>=target) return rooms[i];
    return -1;
}

int main(){
    vector<int> rooms = {15, 10, 30, 50, 25};
    cout<<solve(rooms,20);
    return 0;
}

