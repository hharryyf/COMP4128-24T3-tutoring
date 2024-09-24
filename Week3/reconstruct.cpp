#include <bits/stdc++.h>
#define LEFT (index<<1)
#define RIGHT (index<<1|1)
#define MID ((l+r)>>1)
#define MAX_SIZE 524312
using namespace std;

int f[MAX_SIZE], idx[MAX_SIZE];
bool merged[MAX_SIZE];

int find(int x) {
    if (x == f[x]) return x;
    return f[x] = find(f[x]);
}

void unionset(int x, int y) {
    int fx = find(x), fy = find(y);
    f[fx] = fy;
}

void build(int l, int r, int index) {
    if (l > r) return;
    f[index] = index;
    if (l == r) {
        idx[l] = index;
        return;
    }

    build(l, MID, LEFT);
    build(MID + 1, r, RIGHT);
}

void pushdown(int l, int r, int index) {
    if (merged[index] || l == r) return;
    unionset(index, LEFT);
    unionset(index, RIGHT);
    merged[index] = true;
    pushdown(l, MID, LEFT);
    pushdown(MID + 1, r, RIGHT);
}

void update(int start, int end, int l, int r, int index, int x) {
    if (start > end || l > r || start > r || l > end) return;
    if (start <= l && r <= end) {
        unionset(x, index);
        pushdown(l, r, index);
        return;
    }

    if (end <= MID) {
        update(start, end, l, MID, LEFT, x);
    } else if (start >= MID + 1) {
        update(start, end, MID + 1, r, RIGHT, x);
    } else {
        update(start, end, l, MID, LEFT, x);
        update(start, end, MID + 1, r, RIGHT, x);
    }
}

/*
8 6
3 2 5
1 2 5
3 2 5
2 4 7
2 1 2
3 1 7

NO
YES
YES


*/

int main() {
    int N, Q;
    scanf("%d%d", &N, &Q);
    build(1, N, 1);
    while (Q-- > 0) {
        int p, x, y;
        scanf("%d%d%d", &p, &x, &y);
        if (p == 1) {
            update(y, y, 1, N, 1, idx[x]);
        } else if (p == 2) {
            update(x + 1, y, 1, N, 1, idx[x]);
        } else {
            printf("%s\n", find(idx[x]) == find(idx[y]) ? "YES" : "NO");
        }
    }
    return 0;
}