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

// unordered_map<ll, int> occ;
// for programming competitions, try to use map instead of unordered_map
// even if unordered_map is hash and has O(1) average time

int main() {
    scanf("%d%d", &N, &K);
    for (int i = 1; i <= N; ++i) {
        ll x, t;
        scanf("%lld%lld", &x, &t);
        occ[x * K - t]++;
    }

    int ans = 0;
    for (auto &it : occ) {
        ans = max(ans, it.second);
    }

    printf("%d\n", ans);
    return 0;
}