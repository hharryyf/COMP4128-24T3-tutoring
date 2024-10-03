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
    if (l > r) return 0;
    if (l == r) return 1;
    if (dp[l][r] != -1) return dp[l][r];
    int ans = 1 + f(l+1, r);
    for (int k = l + 1; k <= r; ++k) {
        if (s[k] == s[l]) {
            ans = min(ans, f(l+1, k) + f(k+1, r));
        }
    }

    dp[l][r] = ans;

    return ans;
}

int main() {
    scanf("%d", &N);
    scanf("%s", s + 1);
    memset(dp, -1, sizeof(dp));
    printf("%d\n", f(1, N));
    return 0;
}