#include <bits/stdc++.h>
using namespace std;
#define MAX_CHAR 26

//using recursion
// void print(string str,int index){
//     if(index == str.size()){
//         cout<<str<<endl;
//         return;
//     }
//     if(str[index] == '?'){
//         str[index] = '0';
//         print(str,index+1);
//         str[index] = '1';
//         print(str,index+1);
//     }else print(str,index+1);
// }

// using queue
void print(string str){
    queue<string> q({str});
    while(!q.empty()){
        string str = q.front();q.pop();
        int index = str.find('?');
        if(index != string::npos){
            str[index] = '0';
            q.push(str);
            str[index] = '1';
            q.push(str);
        }else cout<<str<<endl;
    }
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/generate-all-binary-strings-from-given-pattern/
	string str = "1??0?101";
    //print(str, 0);
    print(str);
    return 0;
}

