#include <bits/stdc++.h>
using namespace std;


int pre[3001][3001];

int rectangle(int R,int C,int H,int W,int Q[3001][3001]) {
    
}


int a[3001][3001];

int main() {
    int R, C, H, W, i, j;
    scanf("%d%d%d%d", &R, &C, &H, &W);
    for (i = 0; i < R; ++i) {
        for (j = 0 ; j < C; ++j) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("%d\n", rectangle(R, C, H, W, a));
    return 0;
}