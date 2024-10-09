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

    
    return 0;
}