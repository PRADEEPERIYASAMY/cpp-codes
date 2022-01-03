#include <bits/stdc++.h> 
using namespace std; 

int firstPetrolPump(int petrol[],int dist[],int n){
    int start = 0,curr_pet = 0;
    int pre_pet = 0;
    for (int i = 0; i < n; i++) {
        curr_pet+=(petrol[i]-dist[i]);
        if(curr_pet<0){
            start = i+1;
            pre_pet+=curr_pet;
            curr_pet =0;
        }
    }
    return (curr_pet+pre_pet)>= 0?start+1:-1;
}

int main() {
	int petrol[] = {50,10,60,100};
	int dist[] = {30,20,100,10};
	cout<<firstPetrolPump(petrol,dist,4);
	return 0;
}

