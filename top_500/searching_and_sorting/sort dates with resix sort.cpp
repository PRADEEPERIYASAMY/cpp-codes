using namespace std;
#include <bits/stdc++.h>

int getMax(int arr[][3],int n,int q){
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++) maxi = max(maxi,arr[i][q]);
    return maxi;
}

void sortDatesUtil(int arr[][3],int n,int q){
    int maxi = getMax(arr,n,q);
    int p = 1;
    while(maxi>0){
        int count[10] = {0};
        for (int i = 0; i < n; i++) count[(arr[i][q]/p)%10]++;
        for (int i = 1; i < 10; i++) count[i]+=count[i-1];
        int ans[n][3];
        for (int i = n-1; i >= 0; i--) {
            int lastDigit = (arr[i][q]/p)%10;
            for (int j = 0; j < 3; j++) ans[count[lastDigit]-1][j] = arr[i][j];
            count[lastDigit]--;
        }
        for (int i = 0; i < n; i++) for (int j = 0; j < 3; j++) arr[i][j] = ans[i][j];
        p*=10;maxi/=10;
    }
}

void sortDates(int dates[][3],int n){
    sortDatesUtil(dates,n,0);
    sortDatesUtil(dates,n,1);
    sortDatesUtil(dates,n,2);
}

void printArr(int arr[][3], int n){
   for(int i=0;i<n;i++){
        for(int j=0;j<3;j++) cout<<arr[i][j]<<" ";
        cout<<endl;
    }
}
 
int main(){
    int dates[][3] = {{20,  1, 2014},
                    {25,  3, 2010},
                    { 3, 12, 2000},
                    {18, 11, 2000},
                    {19,  4, 2015},
                    { 9,  7, 2005}};
    int n = sizeof(dates)/sizeof(dates[0]);
    sortDates(dates,n);
    cout<<"\nSorted Dates\n";
    printArr(dates,n);
    return 0;
}

