#include <bits/stdc++.h>

using namespace std;

char ss[111];
int N;
vector<int> rowbit;
int g[15][15];
int sm[15][(1 << 15) + 1];
int dp[15][(1 << 15) + 1];

void init() {
    rowbit.clear();
    for (int i = 0 ; i < N; ++i) {
        for (int j = 0 ; j < (1 << N); ++j) {
            dp[i][j] = -100000000;
            sm[i][j] = 0;
        }
    }
}


int main() {

    int i, j, k;
    while (fgets(ss, 111, stdin) != NULL) {
        // parse and read in the grid
        // you don't need to do something similar for the course
        N = 0;
        int curr = 0;
        for (i = 0 ; i < (int) strlen(ss); ++i) {
            if (ss[i] == ' ' || ss[i] == '\n') {
                g[0][N++] = curr;
                curr = 0;
            } else {
                curr = curr * 10 + (ss[i] - '0');
            }
        }

        for (i = 1; i < N; ++i) {
            for (j = 0; j < N; ++j) {
                scanf("%d", &g[i][j]);
            }
        }

        getchar();
        getchar();
        // assume now N is the size of the grid
        // g[i][j] stores the integer on the i-th row and j-th column of the grid
        // we do problem solving here
        init();
        
        for (i = 0 ; i < (1 << N); ++i) {
            if ((i & (i << 1)) == 0) rowbit.push_back(i);
        }

        for (i = 0 ; i < N; ++i) {
            for (j = 0; j < (1 << N); ++j) {
                for (k = 0 ; k < N; ++k) {
                    if (j & (1 << k)) sm[i][j] += g[i][k]; 
                } 
            }
        }

        for (auto &bt : rowbit) {
            dp[0][bt] = sm[0][bt];
        }

        for (i = 1 ; i < N; ++i) {
            for (auto &m : rowbit) {
                for (auto &mp : rowbit) {
                    // calculate dp[i][m] based on dp[i-1][mp]
                    if (m & mp) continue;
                    if ((m << 1) & mp) continue;
                    if ((m >> 1) & mp) continue;
                    dp[i][m] = max(dp[i][m], dp[i-1][mp] + sm[i][m]);
                }
            }
        }

        int ans = 0;

        for (auto &bt : rowbit) {
            ans = max(ans, dp[N-1][bt]);
        }

        printf("%d\n", ans);
    }
    return 0;
}