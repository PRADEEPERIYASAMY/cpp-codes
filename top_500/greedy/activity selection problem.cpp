#include <bits/stdc++.h>
using namespace std;

// when given array is sorted
void printMaxActivities(int s[],int f[],int n){
    int i,j;
    cout<<"Following activities are selected "<<"\n";
    i = 0;
    cout<<" "<<i;
    for (j  = 1; j < n; j++) {
        if(s[j]>= f[i]){
            cout<<" "<<j;
            i = j;
        }
    }
}

// when unsorted arr is given - use sort or priority queue 

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/activity-selection-problem-greedy-algo-1/
	int s[] =  {1, 3, 0, 5, 8, 5};
    int f[] =  {2, 4, 6, 7, 9, 9};
    int n = sizeof(s)/sizeof(s[0]);
    printMaxActivities(s, f, n);
    return 0;
}

