#include <bits/stdc++.h>
#define MAX_SIZE 2011
typedef long long ll;
using namespace std;

/*
3
2 3
1 1
3 2
3 2 3
3 2 3

ans = 
8
3
1 2 3 
0



3
2 1
1 2
3 3
23 2 23
3 2 3

ans = 
27
1
2 
2
1 2
2 3
*/

struct edge {
    int u, v;
    ll w;
    bool operator <(edge &other) {
        return w < other.w;
    }
};

ll x[MAX_SIZE], y[MAX_SIZE], k[MAX_SIZE], c[MAX_SIZE];
int N;

vector<edge> edg;

int f[MAX_SIZE];

int find(int x) {
    if (f[x] == x) return x;
    return f[x] = find(f[x]);
}

void unionset(int x, int y) {
    int fx = find(x), fy = find(y);
    f[fx] = fy;
}

vector<pair<int, int>> conn;
vector<int> pw;

int main() {
    int i, j;
    ll ans = 0;
    scanf("%d", &N);
    for (i = 0 ; i <= N; ++i) f[i] = i;
    for (i = 1; i <= N; ++i) scanf("%lld%lld", &x[i], &y[i]);
    for (i = 1; i <= N; ++i) scanf("%lld", &c[i]);
    for (i = 1; i <= N; ++i) scanf("%lld", &k[i]);
    
    return 0;
}