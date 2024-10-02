#include <bits/stdc++.h>
#define MAX_SIZE 100011
using namespace std;
typedef long long ll;
int N;

ll dp[MAX_SIZE];
int cnt[MAX_SIZE];


/*

2
1 2

ans = 2

3
1 2 3

ans = 4

9
1 2 1 3 2 2 2 2 3

ans = 10

*/

int main() {
    int i;
    scanf("%d", &N);
    for (i = 1; i <= N; ++i) {
        int v;
        scanf("%d", &v);
        cnt[v]++;
    }

    for (i = 1; i < MAX_SIZE; ++i) {
        dp[i] = max(dp[i-1], dp[i-2] + 1ll * cnt[i] * i);
    }

    printf("%lld\n", dp[MAX_SIZE - 1]);
    return 0;
}