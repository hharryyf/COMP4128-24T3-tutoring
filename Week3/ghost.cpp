#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

/*
3 4
1 2
2 6
2 9

2

4 1
2 4
3 3
4 6
7 7
2

5 2
1 5
1 5
1 5
2 5
2 5
3

*/

int N, K;
map<ll, int> occ;

int main() {
    scanf("%d%d", &N, &K);
    for (int i = 1; i <= N; ++i) {
        ll x, t;
        scanf("%lld%lld", &x, &t);
        occ[x * K - t]++;
    }

    int ans = 0;
    for (auto &mp : occ) {
        ans = max(ans, mp.second);
    }

    printf("%d\n", ans);
    return 0;
}