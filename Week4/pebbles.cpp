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
        
        // we need to find all bit representation of a row that is valid
        for (i = 0 ; i < (1 << N); ++i) {
            if ((i & (i << 1)) == 0) rowbit.push_back(i);
        }

        for (i = 0 ; i < N; ++i) {
            for (j = 0 ; j < (1 << N); ++j) {
                for (k = 0 ; k < N; ++k) {
                    if ((j >> k) & 1) {
                        sm[i][j] += g[i][k];
                    }
                } 
            }
        }
        // base case
        for (auto &valid : rowbit) {
            dp[0][valid] = sm[0][valid];
        }

        // recursive case
        for (i = 1; i < N; ++i) {
            for (auto &m : rowbit) {
                for (auto &mp : rowbit) {
                    if (m & mp) continue; // they share an edge verically
                    if (m & (mp << 1)) continue; // they share an edge diagnally
                    if ((m << 1) & mp) continue; // they share an edge diagnally
                    dp[i][m] = max(dp[i][m], dp[i-1][mp] + sm[i][m]);
                }
            }
        }

        int ans = 0;
        for (auto &m : rowbit) {
            ans = max(ans, dp[N-1][m]);
        }

        cout << ans << endl;
    }
    return 0;
}