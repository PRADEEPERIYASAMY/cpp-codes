#include <bits/stdc++.h>
using namespace std;

char* removeUtil(char *str,char &lastRemoved){
    if(str[0] == '\0' || str[1] == '\0') return str;
    if(str[0] == str[1]){
        lastRemoved = str[0];
        while(str[1] && str[0] == str[1]) str++;
        str++;
        return removeUtil(str,lastRemoved);
    }
    char* rem = removeUtil(str+1,lastRemoved);
    if(rem[0] && rem[0] == str[0]){
        lastRemoved = str[0];
        return rem+1;
    }
    if(rem[0] == '\0' && lastRemoved == str[0]) return rem;
    rem--;
    rem[0] = str[0];
    return rem;
}

char* remove(char* str){
    char lastRemoved = '\0';
    return removeUtil(str,lastRemoved);
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/recursively-remove-adjacent-duplicates-given-string/
	char str1[] = "geeksforgeeg";
    cout << remove(str1) << endl;
    return 0;
}

