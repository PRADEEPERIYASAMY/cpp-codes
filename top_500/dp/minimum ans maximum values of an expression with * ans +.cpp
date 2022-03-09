#include <bits/stdc++.h>
using namespace std;

bool isOperator(char op){
    return op == '+' || op == '*';
}

void printMinAndMaxValueOfExp(string exp){
    vector<int> num;
    vector<char>opr;
    string tmp = "";
    for (int i = 0; i < exp.size(); i++) {
        if(isOperator(exp[i])){
            opr.push_back(exp[i]);
            num.push_back(atoi(tmp.c_str()));
            tmp = "";
        }else tmp += exp[i];
    }
    num.push_back(atoi(tmp.c_str()));
    int len = num.size();
    int minVal[len][len];
    int maxVal[len][len];
    for (int i = 0; i < len; i++) for (int j = 0; j <len; j++) minVal[i][j] = INT_MAX,maxVal[i][j] = INT_MIN;
    for (int i = 0; i < len; i++) minVal[i][i] = maxVal[i][i] = num[i];
    for (int gap = 2; gap <=len; gap++) {
        for (int i = 0; i < len - gap+1; i++) {
            int j = i+gap -1;
            for (int k = i; k < j; k++) {
                int mintmp,maxtmp;
                mintmp = maxtmp = 0;
                if(opr[k] == '+'){
                    mintmp = minVal[i][k] + minVal[k+1][j];
                    maxtmp = maxVal[i][k] + maxVal[k+1][j];
                }else if(opr[k] == '*'){
                    mintmp = minVal[i][k] * minVal[k+1][j];
                    maxtmp = maxVal[i][k] * maxVal[k+1][j];
                }
                minVal[i][j] = min(minVal[i][j],mintmp);
                maxVal[i][j] = max(maxVal[i][j],maxtmp);
            }
        }
    }
    cout<<"Minimum value : "<<minVal[0][len-1]<<"\n";
    cout<<"Maximum value : "<<maxVal[0][len-1]<<"\n";
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/minimum-maximum-values-expression/
	string expression = "1+2*3+4*5";
    printMinAndMaxValueOfExp(expression);
    return 0;
}
