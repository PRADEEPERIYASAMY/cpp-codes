#include <bits/stdc++.h>
using namespace std;

// recursion
// bool isInterleaved(char *A,char *B,char *C){
//     if(!(*A||*B||*C)) return true;
//     if(*C == '\0') return false;
//     return ((*C == *A) && isInterleaved(A+1,B,C+1)) || ((*C == *B) && isInterleaved(A,B+1,C+1));
// }

// dp 
bool isInterleaved(char *A,char *B,char *C){
    int M = strlen(A), N = strlen(B);
    bool dp[M+1][N+1] = {0};
    if(M+N != strlen(C)) return false;
    for (int i = 0; i <= M; i++) {
        for (int j = 0; j <= N; j++) {
            if(i == 0 && j == 0) dp[i][j] = true;
            else if(i == 0) if(B[j-1] == C[j-1]) dp[i][j] = dp[i][j-1];
            else if(j == 0) if(A[i-1] == C[i-1]) dp[i][j] = dp[i-1][j];
            else if(A[i-1] == C[i+j -1] && B[j-1] != C[i+j-1]) dp[i][j] = dp[i-1][j];
            else if(A[i-1] != C[i+j -1] && B[j-1] == C[i+j-1]) dp[i][j] = dp[i][j-1];
            else if(A[i-1] == C[i+j-1] && B[j-1] == C[i+j-1]) dp[i][j] = dp[i-1][j] || dp[i][j-1];
        }
    }
    return dp[M][N];
}

void test(char* A, char* B, char* C){
    if (isInterleaved(A, B, C))cout << C << " is interleaved of "<< A << " and " << B << endl;
    else cout << C << " is not interleaved of " << A << " and " << B << endl;
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/find-if-a-string-is-interleaved-of-two-other-strings-dp-33/
    test("XXY", "XXZ", "XXZXXXY");
    test("XY", "WZ", "WZXY");
    test("XY", "X", "XXY");
    test("YX", "X", "XXY");
    test("XXY", "XXZ", "XXXXZY");
    return 0;
}
