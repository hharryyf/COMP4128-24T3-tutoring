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
    // init
    
    while (Q-- > 0) {
        int p, x, y;
        scanf("%d%d%d", &p, &x, &y);
        if (p == 1) {
        
        } else if (p == 2) {
        
        } else {
        
        }
    }
    return 0;
}