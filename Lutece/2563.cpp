#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
using ll = long long;

int risks[maxn];

struct node {
    int no, val = 0;
    int ith = 0, pre, next;
} f[maxn];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        f[i].no = i;
        f[i].ith = 1;
        f[i].next = f[i].pre = 0;
        cin >> f[i].val;
    }
    
    return 0;
}