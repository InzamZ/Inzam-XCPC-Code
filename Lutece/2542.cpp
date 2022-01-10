#include <bits/stdc++.h>
using namespace std;
#define maxn 100010
priority_queue<int>q;
int t[maxn];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, cnt = 0, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> t[i];
    sort(t + 1, t + 1 + n);
    cnt = 1;
    for (int i = 2; i <= n; ++i) {
        if (t[i] == t[i - 1])
            ++cnt;
        else
            q.push(cnt), cnt = 1;
    }
    q.push(cnt);
    while (q.size() >= 3) {
        int a1, a2, a3;
        ++ans;
        a1 = q.top();
        q.pop();
        a2 = q.top();
        q.pop();
        a3 = q.top();
        q.pop();
        if (a1 - 1)
            q.push(a1 - 1);
        if (a2 - 1)
            q.push(a2 - 1);
        if (a3 - 1)
            q.push(a3 - 1);
    }
    cout << ans << endl;
    return 0;
}