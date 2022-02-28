#include <bits/stdc++.h>
using namespace std;
#define MAX_CAHRS 26

int runCustomerSimulation(int n,string str){
    int visited[MAX_CAHRS] = {0};
    int res = 0;
    int occupied = 0;
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - 'A';
        if(visited[ind] == 0){
            visited[ind] = 1;
            if(occupied<n){
                occupied++;
                visited[ind] = 2;
            }else res++;
        }else{
            if(visited[ind] == 2) occupied--;
            visited[ind] = 0;
        }
    }
    return res;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/function-to-find-number-of-customers-who-could-not-get-a-computer/
	cout << runCustomerSimulation(2, "ABBAJJKZKZ") << endl;
    cout << runCustomerSimulation(3, "GACCBDDBAGEE") << endl;
    cout << runCustomerSimulation(3, "GACCBGDDBAEE") << endl;
    cout << runCustomerSimulation(1, "ABCBCA") << endl;
    cout << runCustomerSimulation(1, "ABCBCADEED") << endl;
    return 0;
}

