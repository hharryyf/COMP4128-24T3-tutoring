#include <bits/stdc++.h>
#define MAX_SIZE 50011
using namespace std;

// string
char s[MAX_SIZE];
// N is the length
// tol is the total number of letters (not ?) in the window
// distinct is  the total number of distinct letters (not ?) in the window
int N, tol = 0, distinct = 0;
// cnt[i] is the occurence of the i-th letter in the window
int cnt[27];

// [aaabb] distinct = 2
// [abb]  cnt[a] = 1 cnt[b] = 2 distinct = 2 
// remove a
// cnt[a] = 0 [bb] distinct = 1
void add(char ch) {
    if (ch == '?') return;
    tol += 1;
    cnt[ch - 'A']++;
    if (cnt[ch - 'A'] == 1) distinct++;
}

void del(char ch) {
    if (ch == '?') return;
    tol -= 1;
    cnt[ch - 'A']--;
    if (cnt[ch - 'A'] == 0) distinct--;
}

bool query() {
    return tol == distinct;
}

int main() {
    scanf("%s", s + 1);
    N = strlen(s + 1);
    int i, good = 0, j;
    for (i = 1; i <= N; ++i) {
        add(s[i]);
        // printf("%d %d\n", tol, distinct);
        // TODO
        if (i >= 26 && query()) {
            // printf("%d %d\n", tol, distinct);
            // for (j = 0; j < 26; ++j) {
            //     printf("cnt[%d] = %d\n", j, cnt[j]);
            // }
            // s[i-25, i] is an 'all distinct' substring, and it's nice
            good = 1;
            vector<char> rem;
            for (j = 0; j < 26; ++j) {
                if (cnt[j] == 0) {
                    rem.push_back('A' + j);
                }
            }

            for (j = i - 25; j <= i; ++j) {
                if (s[j] == '?') {
                    s[j] = rem.back();
                    rem.pop_back();
                }
            }

            break;
        }

        // i >= 26, using 1-index
        if (i >= 26) del(s[i-25]);
    }

    for (int i = 1; i <= N; ++i) {
        if (s[i] == '?') s[i] = 'A';
    }

    if (good) {
        printf("%s\n", s + 1);
    } else {
        printf("-1\n");
    }

    return 0;
}

/*
ABC??FGHIJK???OPQR?TUVWXY?

WELCOMETOCODEFORCESROUNDTHREEHUNDREDANDSEVENTYTWO
-1

??????????????????????????

AABCDEFGHIJKLMNOPQRSTUVW??M
-1

*/