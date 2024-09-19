#include <bits/stdc++.h>
using namespace std;

// https://dmoj.ca/problem/ioi10p3


/*

5 5 3 3 

 5 11 12 16 25
17 18  2  7 10
4 23 20  3  1
24 21 19 14  9
6 22  8 13 15

9
*/

int pre[3001][3001];

int rectangle(int R,int C,int H,int W,int Q[3001][3001]) {
    int i, j;
    for (i = R; i >= 1; --i) {
        for (j = C; j >= 1; --j) {
            Q[i][j] = Q[i-1][j-1];
        }
    }

    // a function taking a parameter K and return a boolean value
    // [&] 
    // check is going to return true if and only if 
    // there exists a submatrix of size H * W such that the median in the submatrix
    // is <= K
    auto check = [&](int K) -> bool {
        for (i = 1; i <= R; ++i) {
            for (j = 1; j <= C; ++j) {
                // replace all elements in Q with +1 if Q[i][j] <= K
                // -1 if Q[i][j] > K
                if (Q[i][j] <= K) {
                    pre[i][j] = 1;
                } else {
                    pre[i][j] = -1;
                }
            }
        }

        // initialize 2-d prefix sum
        for (i = 1; i <= R; ++i) {
            for (j = 1; j <= C; ++j) {
                pre[i][j] += pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
            }
        }

        // check if there exists a submatrix of size H * W such that the sum of the submatrix is > 0
        for (i = H; i <= R; ++i) {
            for (j = W; j <= C; ++j) {
                if (pre[i][j] + pre[i-H][j-W] - pre[i-H][j] - pre[i][j-W] > 0) {
                    return true;
                }
            }
        } 

        return false;
    };

    int low = 1, high = R * C, ans = R * C;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(mid)) {
            high = mid - 1;
            ans = mid;
        } else {
            low = mid + 1;
        }
    }
    return ans;
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
