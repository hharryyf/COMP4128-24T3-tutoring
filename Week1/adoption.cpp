#include <bits/stdc++.h>
#define MAX_SIZE 200011
typedef long long ll;
using namespace std;

int N;
ll c[MAX_SIZE], d[MAX_SIZE];
ll a[MAX_SIZE];

int main() {
    int i;
    ll X = 0, Y = 0;
    scanf("%d", &N);        
    for (i = 1; i <= 2 * N; ++i) {
        scanf("%lld%lld", &c[i], &d[i]);
        a[i] = c[i] - d[i];
    }

    for (i = 1; i <= 2 * N; ++i) X += d[i];
    sort(a + 1, a + 1 + N * 2);

    for (i = N + 1; i <= 2 * N; ++i) Y += a[i];

    printf("%lld\n", X + Y);
    return 0;
}

/*
2
1 2
2 1
0 3
2 -1

9

2
1 2
2 1
0 3
2 5

11

2
1 2
2 1
0 3
-1 -2

6

*/