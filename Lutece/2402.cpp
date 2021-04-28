#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll ans=0;

struct Node
{
    int l, r;
    mutable ll value; //
    Node(int a, int b, long long c) : l(a), r(b), value(c) {}
    Node(int a) : l(a), r(0), value(0) {}

    bool operator<(const Node &o) const
    {
        return l < o.l;
    }
};

set<Node> s;

set<Node>::iterator split(int pos)
{
    set<Node>::iterator it = s.lower_bound(Node(pos));
    if (it->l == pos && it != s.end())
        return it; //
    --it;
    if (pos > it->r)
        return s.end(); //
    int L = it->l, R = it->r;
    ll V = it->value;
    s.erase(it);
    s.insert(Node(L, pos - 1, V));
    return s.insert(Node(pos, R, V)).first;
}

void assign(int l, int r, int v)
{
    split(l);
    set<Node>::iterator R = split(r + 1);
    set<Node>::iterator L = split(l);
    for (auto it = L; it != R; ++it)
    {
        if (it->value != v)
            ans += (it->r - it->l + 1);
    }
    s.erase(L,R);
    s.insert(Node(l, r, v));
}

int main()
{
    int n, m;
    ll num;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &num);
        s.insert(Node(i, i, num));
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        int l, r, c;
        scanf("%d %d %d", &l, &r, &c);
        ans = 0;
        assign(l, r, c);
        printf("%lld\n", ans);
    }
    return 0;
}
