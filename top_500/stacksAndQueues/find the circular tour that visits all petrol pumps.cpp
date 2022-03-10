#include <bits/stdc++.h>
using namespace std;

struct petrolPump{
    int petrol,distance;
};

// int printTour(petrolPump p[],int n){
//     int start = 0,defict = 0, capacity = 0;
//     for (int i = 0; i < n; i++) {
//         capacity += p[i].petrol - p[i].distance;
//         if(capacity<0){
//             start = i+1;
//             defict += capacity;
//             capacity = 0;
//         }
//     }
//     return (capacity+defict>= 0)?start:-1;
// }

int printTour(petrolPump arr[],int n){
    int start;
    for (int i = 0; i < n; i++) {
        if(arr[i].petrol >= arr[i].distance){
            start = i;
            break;
        }
    }
    int currPetrol = 0;
    int i;
    for (int i = start; i < n; ) {
        currPetrol += (arr[i].petrol - arr[i].distance);
        if(currPetrol<0){
            i++;
            for ( ; i < n; i++) {
                if(arr[i].petrol>= arr[i].distance){
                    start = i;
                    currPetrol = 0;
                    break;
                }
            }
        }else i++;
    }
    if(currPetrol <0) return -1;
    for (int i = 0; i < start; i++) {
        currPetrol += arr[i].petrol - arr[i].distance;
        if(currPetrol < 0) return -1;
    }
    return start;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/find-a-tour-that-visits-all-stations/
	petrolPump arr[] = { { 6, 4 }, { 3, 6 }, { 7, 3 } };
    int n = sizeof(arr) / sizeof(arr[0]);
    int start = printTour(arr, n);
    (start == -1) ? cout << "No solution": cout << "Start = " << start;
    return 0;
}