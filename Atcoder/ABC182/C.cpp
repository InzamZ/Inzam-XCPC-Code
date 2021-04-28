#include <bits/stdc++.h>
using namespace std;

char N[20], ans[20];
bool t[20];
int cnt = 0, len;

void dfs(int n, int top, int beg)
{
    if (top == n) {
        if (cnt % 3 == 0) {
            printf("%d\n", len - n);
            exit(0);
        }
        else
            return ;
    }
    for (int i = beg; i < len; i++) {
        if (t[i] == false) {
            ans[top] = N[i];
            t[i] = true;
            cnt += (N[i] - '0');
            dfs(n, top + 1, i + 1);
            t[i] = false;
            cnt -= (N[i] - '0');
        }
    }
}

int main()
{
    scanf ("%s", N);
    len = strlen(N);
    for (int i = len; i >= 1; i--)
        dfs(i, 0, 0);
    printf("%d\n", -1);
    return 0;
}
