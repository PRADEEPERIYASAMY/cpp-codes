#include <bits/stdc++.h>
using namespace std;

int const MAX_CHAIR = 26;

void countFreq(string str,int freq[],int len){
    for (int i = 0; i < len; i++) freq[str[i] - 'a']++;
}

bool canMakePalindrome(int freq[],int len){
    int count_odd = 0;
    for (int i = 0; i < MAX_CHAIR; i++) if(freq[i]%2 != 0) count_odd++;
    if(len %2 == 0) {
        if(count_odd >0) return false;
        else return true;
    }
    if(count_odd!=1) return false;
    return true;
}

string findOddAndRemove(int freq[]){
    string odd = "";
    for (int i = 0; i < MAX_CHAIR; i++) {
        if(freq[i]%2 != 0){
            freq[i]--;
            odd = odd+(char)(i+'a');
            return odd;
        }
    }
    return odd;
}

string findPalindromicString(string str){
    int len = str.size();
    int freq[MAX_CHAIR] = {0};
    countFreq(str,freq,len);
    if(!canMakePalindrome(freq,len)) return "No palindromic string";
    string odd = findOddAndRemove(freq);
    string front = "",rear = "";
    for (int i = 0; i < MAX_CHAIR; i++) {
        string temp = "";
        if(freq[i]!=0){
            char ch = (char)(i+'a');
            for (int j = 1; j <= freq[i]/2; j++) temp+=ch;
            front = front+temp;
            rear = temp+rear;
        }
    }
    return front + odd + rear;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/lexicographically-first-palindromic-string/
	string str = "malayalam";
    cout << findPalindromicString(str);
    return 0;
}

