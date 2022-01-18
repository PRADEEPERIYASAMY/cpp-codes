using namespace std;
#include <bits/stdc++.h>

//int solve(int n, int e, int o, int t) {
//    int count = 0;
//    double ta = t*1.0;
//    double na = n*1.0;
//    double ea = e*1.0;
//    double oa = o*1.0;
//    while(na<ta){
//        if(count%2 == 0){
//            na+=((na/100)*ea);
//        }else{
//            na+=((na/100)*oa);
//        }
//        count++;
//    }
//
//    return count;
//}

int solve(int n,int e,int o,int t){
    double y1 = e/100.0+1;
    double y2 = o/100.0+1;
    double goal = (double) t/n;
    int years = 2*ceil(log(goal)/log(y1*y2));
    if(n*pow(y1*y2,years/2)/y2>= t) years--;
    return years;
}

int main(){
    cout<<solve(100,20,10,130);
    return 0;
}

