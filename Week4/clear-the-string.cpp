#include <bits/stdc++.h>
#define MAX_SIZE 511
using namespace std;

int dp[MAX_SIZE][MAX_SIZE];
int N;
char s[MAX_SIZE];


/*


5
abaca

ans = 3

8
abcddcba

ans = 4

*/

int f(int l, int r) {
    
}

int main() {
    scanf("%d", &N);
    scanf("%s", s + 1);
    memset(dp, -1, sizeof(dp));
    printf("%d\n", f(1, N));
    return 0;
}