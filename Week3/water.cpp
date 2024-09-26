#include <bits/stdc++.h>
#define MID ((l+r)>>1)
#define LEFT (index<<1)
#define RIGHT ((index<<1)|1)
#define MAX_SIZE 1048597
using namespace std;

int invalid = -1;
// range tree supports range update, set [l, r] to val
// range sum query, query the sum of [l, r]
struct segt {
    int val, lz;
};

segt tree[MAX_SIZE];

void pushdown(int l, int r, int index) {
    if (l > r) return;
    if (l != r && tree[index].lz != invalid) {
        tree[LEFT].lz = tree[index].lz;
        tree[RIGHT].lz = tree[index].lz;
        tree[RIGHT].val = (r - MID) * tree[index].lz;
        tree[LEFT].val = (MID - l + 1) * tree[index].lz;
    }

    tree[index].lz = invalid;
}

// set [start, end] to val
void update(int start, int end, int l, int r, int index, int val) {
    if (start > end || l > r || start > r || l > end) return;
    pushdown(l, r, index);
    if (start <= l && r <= end) {
        tree[index].val = (r - l + 1) * val;
        tree[index].lz = val;
        return;
    }

    if (end <= MID) {
        update(start, end, l, MID, LEFT, val);
    } else if (start >= MID + 1) {
        update(start, end, MID + 1, r, RIGHT, val);
    } else {
        update(start, end, l, MID, LEFT, val);
        update(start, end, MID + 1, r, RIGHT, val);
    }

    tree[index].val = tree[LEFT].val + tree[RIGHT].val;
}
// range sum of [start, end]
int query(int start, int end, int l, int r, int index) {
    if (start > end || l > r || start > r || l > end) return 0;
    pushdown(l, r, index);
    if (start <= l && r <= end) return tree[index].val;
    if (end <= MID) return query(start, end,l, MID, LEFT);
    else if (start >= MID + 1) return query(start, end, MID + 1, r, RIGHT);
    return query(start, end,l, MID, LEFT) + query(start, end, MID + 1, r, RIGHT);
}
// construct the range tree
void build(int l, int r, int index) {
    if (l > r) return;
    tree[index].lz = invalid;
    if (l == r) return;
    build(l, MID, LEFT);
    build(MID + 1, r, RIGHT);
}

vector<int> g[MAX_SIZE];
int sz[MAX_SIZE], id[MAX_SIZE], parent[MAX_SIZE], N;
int cnt = 0;

void dfs(int v, int pre) {
    sz[v] = 1;
    id[v] = ++cnt;
    parent[v] = pre;
    for (auto nv : g[v]) {
        if (nv != pre) {
            dfs(nv, v);
            sz[v] += sz[nv];
        }
    }
}

int main() {
    int i;
    scanf("%d", &N);
    for (i = 1; i < N; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }


    dfs(1, 0);
    build(1, N, 1);

    int Q;
    scanf("%d", &Q);
    while (Q-- > 0) {
        int tp, v;
        scanf("%d%d", &tp, &v);
        if (tp == 1) {
            // fill node v with water
            int full = query(id[v], id[v] + sz[v] - 1, 1, N, 1) == sz[v];

            update(id[v], id[v] + sz[v] - 1, 1, N, 1, 1);
            if (!full) {
                update(id[parent[v]], id[parent[v]], 1, N ,1, 0);
            }
        } else if (tp == 2) {
            // empty node v
            update(id[v], id[v], 1, N, 1, 0);
        } else {
            // query if node v has water
            printf("%d\n", query(id[v], id[v] + sz[v] - 1, 1, N, 1) == sz[v]);
        }

    }
    return 0;
}