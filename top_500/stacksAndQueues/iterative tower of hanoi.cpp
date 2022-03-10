#include <bits/stdc++.h>
using namespace std;

void movedisk(char from,char to,int disk){
    cout<<"Move the disk "<<disk<<" from "<<from<<" to "<<to<<"\n";
}

void movediskBetweenPoles(stack<int> &src,stack<int> &dest,char s,char d){
    int pole1TopDisk,pole2TopDisk;
    pole1TopDisk = pole2TopDisk = INT_MIN;
    if(!src.empty()){pole1TopDisk = src.top();src.pop();}
    if(!dest.empty()){pole2TopDisk = dest.top();dest.pop();}
    if(pole1TopDisk == INT_MIN){
        src.push(pole2TopDisk);
        movedisk(d,s,pole2TopDisk);
    }
    else if(pole2TopDisk == INT_MIN){
        dest.push(pole1TopDisk);
        movedisk(s,d,pole1TopDisk);
    }else if(pole1TopDisk>pole2TopDisk){
        src.push(pole1TopDisk);
        src.push(pole2TopDisk);
        movedisk(d,s,pole2TopDisk);
    }else{
        dest.push(pole2TopDisk);
        dest.push(pole1TopDisk);
        movedisk(s,d,pole1TopDisk);
    }
}

void tohIterative(int noDisk,stack<int> &src,stack<int> &aux,stack<int> &dest){
    int i,totalMoves;
    char s ='S',d = 'D',a = 'A';
    if(noDisk%2 == 0) swap(d,a);
    totalMoves = pow(2,noDisk)-1;
    for (int i = noDisk; i >=1; i--) src.push(i);
    for (int i = 1; i <= totalMoves; i++) {
        if(i%3 == 1) movediskBetweenPoles(src,dest,s,d);
        else if(i%3 == 2) movediskBetweenPoles(src,aux,s,a);
        else if(i%3 == 0) movediskBetweenPoles(aux,dest,a,d);
    }
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/iterative-tower-of-hanoi/
	stack<int> src,aux,dest;
	int noDisk = 3;
	tohIterative(noDisk,src,aux,dest);
    return 0;
}
