#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;

char mstack[maxn];
int cnt;

int main()
{
    // ios::sync_with_stdio(false);
    int T, n;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        cnt = 0;
        for (int i = 0; i < n; i++)
        {
            char ch;
            scanf(" %c", &ch);
            if (cnt && mstack[cnt - 1] == '(' && ch == ')')
                cnt--;
            else
                mstack[cnt++] = ch;
        }
        printf("%d\n", cnt);
    }
    return 0;
}