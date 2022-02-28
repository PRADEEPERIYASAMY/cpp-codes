#include <bits/stdc++.h>
using namespace std;

bool checkSentence(string str){
    int len = str.size();
    if(!isupper(str[0])) return false;
    if(str[len-1]!='.') return false;
    int prevState = 0,curState = 0;
    int index = 1;
    while(str[index]){
        if(isupper(str[index])) curState = 0;
        else if(str[index] == ' ') curState = 1;
        else if(islower(str[index])) curState = 2;
        else if(str[index] == '.') curState = 3;
        if(prevState == curState && curState != 2) return false;
        if(prevState == 2 && curState == 0) return false;
        if(curState == 3 && prevState != 1) return str[i+1] == '\0';
        index++;
        prevState = curState;
    }
    return false;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/check-given-sentence-given-set-simple-grammer-rules/
	vector<string> str = { "I love cinema.", "The vertex is S.",
                    "I am single.", "My name is KG.",
                    "I lovE cinema.", "GeeksQuiz. is a quiz site.",
                    "I love Geeksquiz and Geeksforgeeks.",
                    "  You are my friend.", "I love cinema" };
    int n = str.size();
    for (int i = 0; i < n; i++) checkSentence(str[i])? printf("\"%s\" is correct \n", str[i]): printf("\"%s\" is incorrect \n", str[i]);
    return 0;
}

