#include <bits/stdc++.h>
#define MAX_SIZE 100011
using namespace std;

int N, M, K;

/*
4 4 3
1 2
2 3
3 4
4 1

ans = 
1
1 3 

4 5 3
1 2
2 3
3 4
4 1
2 4

ans = 
2
3
2 3 4 

4 6 3
1 2
2 3
3 4
4 1
1 3
2 4

ans = 
2
3
1 2 3 

5 4 5
1 2
1 3
2 4
2 5

ans = 
1
1 4 5 

*/
vector<int> g[MAX_SIZE];
int visited[MAX_SIZE];
int f[MAX_SIZE], depth[MAX_SIZE];

void dfs(int v, int p) {
    visited[v] = 1;
    f[v] = p;
    depth[v] = depth[p] + 1;
    // back vertex
    // we are looking for a backedge between nv and v
    // we want to store the minimal cycle between nv and v
    int back_v = -1;
    for (auto &nv : g[v]) {
        if (nv != p) {
            if (visited[nv]) {
                if (back_v == -1 || depth[back_v] < depth[nv]) {
                    back_v = nv;
                } 
            }
        }
    }

    if (back_v != -1) {
        vector<int> ret;
        int curr = v;
        while (curr != back_v) {
            ret.push_back(curr);
            curr = f[curr];
        }

        ret.push_back(curr);

        if ((int) ret.size() <= K) {
            // we found a simple cycle of size at most K
            printf("2\n");
            printf("%d\n", (int) ret.size());
            for (auto &p : ret) {
                printf("%d ", p);
            }
            printf("\n");
        } else {
            // we found a cycle of size greater than K
            // we print out an independent set instead
            int i, j;
            printf("2\n");
            for (i = 0, j = 0; i < (int) ret.size() && j < (K + 1) / 2; i = i + 2, ++j) {
                printf("%d ", ret[i]);
            }
            printf("\n");
        }
        exit(0);
    }

    for (auto &nv : g[v]) {
        if (!visited[nv]) {
            dfs(nv, v);
        }
    }
}

int main() {
    int i, j;
    scanf("%d%d%d", &N, &M, &K);
    for (i = 1; i <= M; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0);

    vector<int> odd, even;
    for (i = 1; i <= N; ++i) {
        if (depth[i] % 2 == 1) {
            odd.push_back(i);
        } else {
            even.push_back(i);
        }
    }

    if (odd.size() < even.size()) {
        swap(odd, even);
    }

    // the tree case, the graph has no cycle
    printf("2\n");
    for (i = 0, j = 0; i < (int) odd.size() && j < (K + 1) / 2; ++i, ++j) {
        printf("%d ", odd[i]);
    }
    printf("\n");
    return 0;
}