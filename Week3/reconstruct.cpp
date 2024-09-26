#include <bits/stdc++.h>
#define LEFT (index<<1)
#define RIGHT (index<<1|1)
#define MID ((l+r)>>1)
#define MAX_SIZE 524312
using namespace std;

int f[MAX_SIZE], idx[MAX_SIZE];
// merged[index] = true if and only if all nodes in the subtree of index are merged
bool merged[MAX_SIZE];

int find(int x) {
    if (x == f[x]) return x;
    return f[x] = find(f[x]);
}

void unionset(int x, int y) {
    int fx = find(x), fy = find(y);
    f[fx] = fy;
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


void build(int l, int r, int index) {
    if (l > r) return;
    f[index] = index;
    if (l == r) {
        // idx[l] simply means that team [l,l] is represented by "index" in the tree 
        idx[l] = index;
        return;
    }

    build(l, MID, LEFT);
    build(MID + 1, r, RIGHT);
}

void rec_merge(int l, int r, int index) {
    if (l > r) return;
    if (l == r || merged[index]) return;
    merged[index] = true;
    unionset(index, LEFT);
    unionset(index, RIGHT);
    rec_merge(l, MID, LEFT);
    rec_merge(MID + 1, r, RIGHT);
}

// merge pt with range [start, end]
void update(int start, int end, int l, int r, int index, int pt) {
    if (start > end || l > r || start > r || l > end) return;
    if (start <= l && r <= end) {
        // index is a top-level node that we are interested in
        // TODO
        unionset(idx[pt], index);
        rec_merge(l, r, index);
        return;
    }

    if (end <= MID) {
        update(start, end, l, MID, LEFT, pt);
    } else if (start >= MID + 1) {
        update(start, end, MID + 1, r, RIGHT, pt);
    } else {
        update(start, end, l, MID, LEFT, pt);
        update(start, end, MID + 1, r, RIGHT, pt);
    }
}

int main() {
    int N, Q;
    scanf("%d%d", &N, &Q);
    // initize the union-find data structure and the range tree
    build(1, N, 1);
    while (Q-- > 0) {
        int p, x, y;
        scanf("%d%d%d", &p, &x, &y);
        if (p == 1) {
            update(y, y, 1, N, 1, x);
        } else if (p == 2) {
            update(x + 1, y, 1, N, 1, x);
        } else {
            printf("%s\n", find(idx[x]) == find(idx[y]) ? "YES" : "NO");
        }
    }
    return 0;
}