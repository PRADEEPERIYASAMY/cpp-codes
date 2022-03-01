#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value,weight;
};

bool compare(const Item a,const Item b){
    return a.value/a.weight > b.value/b.weight;
}

double fractionalKnapsack(int w,Item arr[],int n){
    sort(arr,arr+n,compare);
    int curWeight = 0;
    double finalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if(curWeight+arr[i].weight<=w){
            curWeight+=arr[i].weight;
            finalValue+=arr[i].value;
        }else{
            int remain = w - curWeight;
            finalValue+=arr[i].value*((double)remain/(double)arr[i].weight);
            break;
        }
    }
    return finalValue;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/fractional-knapsack-problem/
	int W = 50; //    Weight of knapsack
    Item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum value we can obtain = "<< fractionalKnapsack(W, arr, n);
    return 0;
}

