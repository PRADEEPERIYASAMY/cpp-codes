#include <bits/stdc++.h>
using namespace std;

int maxSum(int stack1[],int stack2[],int stack3[],int n1,int n2,int n3){
    int sum1,sum2,sum3;
    sum1 = sum2 =sum3 = 0;
    sum1 = accumulate(stack1,stack1+n1,0);
    sum2 = accumulate(stack2,stack2+n2,0);
    sum3 = accumulate(stack3,stack3+n3,0);
    
    int top1,top2,top3;
    top1 = top2 = top3 = 0;
    while(1){
        if(top1 == n1 && top2 == n2 && top3 == n3) return 0;
        if(sum1 == sum2 && sum2 == sum3) return sum1;
        if(sum1>=sum2 && sum1>=sum3) sum1 -=stack1[top1++];
        else if(sum2>=sum1 && sum2 >= sum3) sum2 -=stack2[top2++];
        else if(sum3>=sum1 && sum3>=sum2) sum3 -=stack3[top3++];
    }
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/find-maximum-sum-possible-equal-sum-three-stacks/
	int stack1[] = { 3, 2, 1, 1, 1 };
    int stack2[] = { 4, 3, 2 };
    int stack3[] = { 1, 1, 4, 1 };
    int n1 = sizeof(stack1) / sizeof(stack1[0]);
    int n2 = sizeof(stack2) / sizeof(stack2[0]);
    int n3 = sizeof(stack3) / sizeof(stack3[0]);
    cout << maxSum(stack1, stack2, stack3, n1, n2, n3)<< endl;
    return 0;
}

