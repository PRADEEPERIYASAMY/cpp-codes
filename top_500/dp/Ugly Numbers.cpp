#include <iostream>
using namespace std;
#include <bits/stdc++.h>

// https://www.geeksforgeeks.org/ugly-numbers/

// method one naive

/*int remainder(int a, int b){
    while(a%b == 0) a/=b;
    return a;
}

bool isUgly(int a){
    a = remainder(a,2);
    a = remainder(a,3);
    a = remainder(a,5);
    
    if(a == 1) return true;
    
    return false;
}

int main() {
	// your code goes here
	
	int nth_ugly;
	cin >> nth_ugly;
	int count = 1;
	int i = 1;
	while(count<nth_ugly){
	    i++;
	    if(isUgly(i)) count++;
	}
	
	cout<<i;
	
	return 0;
}*/

// dp method

int main() {
	// your code goes here
	
	int nth_ugly;
	cin>>nth_ugly;
	
	int i2=0,i3=0,i5=0;
	int next_2 = 2,next_3= 3, next_5 = 5;
	int next_ugly = 1;
	int ugly_arr[nth_ugly];
	
	ugly_arr[0] = 1;
	
	for (int i = 1; i < nth_ugly; i++) {
	    next_ugly = min(next_2,min(next_3,next_5));
	    
	    ugly_arr[i] = next_ugly;
	    
	    if(next_ugly == next_2){
	        i2+=1;
	        next_2 = ugly_arr[i2]*2;
	    }
	    if(next_ugly == next_3){
	        i3+=1;
	        next_3 = ugly_arr[i3]*3;
	    }
	    if(next_ugly == next_5){
	        i5+=1;
	        next_5 = ugly_arr[i5]*5;
	    }
	}
	
	cout<<next_ugly;
	
	return 0;
}

