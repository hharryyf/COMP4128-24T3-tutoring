#include <bits/stdc++.h>
#define MAX_SIZE 511
using namespace std;

char s[MAX_SIZE];

// https://codeforces.com/problemset/problem/1398/B

/*
5
01111001 -> [4, 1]
0000 -> []
111111 -> [6]
101010101 -> [1, 1, 1, 1, 1]
011011110111 -> [2, 4, 3]


*/

int main() {
    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        scanf("%s", s);
        int ans = 0, i, cnt = 0, N = strlen(s);
        vector<int> block;
        for (i = 0 ; i < N; ++i) {
            if (s[i] == '1') {
                cnt++;
            } else {
                if (cnt > 0) {
                    block.push_back(cnt);
                    cnt = 0;
                } 
            }
        }

        if (cnt > 0) {
            block.push_back(cnt);
        }

        sort(block.begin(), block.end(), greater<int>());

        for (i = 0 ; i < (int) block.size(); i += 2) {
            ans += block[i];
        }

        printf("%d\n", ans);
    }
    return 0;
}

/*



5
01111001
0000
111111
101010101
011011110111

4
0
6
3
6

*/
