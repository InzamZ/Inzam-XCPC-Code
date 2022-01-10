#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
using ll = long long;

int son[maxn][2], siz[maxn], datas[maxn];
int tails = 0, sbt = 0;

inline int read()
{
    int X = 0;
    bool flag = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            flag = 0;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        X = (X << 1) + (X << 3) + ch - '0';
        ch = getchar();
    }
    if (flag)
        return X;
    return ~(X - 1);
}

void rotate(int &rt, int k)
{
    int nrt = son[rt][!k]; //new root
    son[rt][!k] = son[nrt][k];
    son[nrt][k] = rt;
    siz[nrt] = siz[rt];
    siz[rt] = siz[son[rt][0]] + siz[son[rt][1]] + 1;
    rt = nrt;
}

void maintain(int &rt, bool k)
{
    if (siz[son[son[rt][k]][k]] > siz[son[rt][!k]])
        rotate(son[rt][k], !k);
    else if (siz[son[son[rt][k]][!k]] > siz[son[rt][!k]])
        rotate(son[rt][k], k), rotate(rt, !k);
    else
        return ;
    maintain(son[rt][0], 0);
    maintain(son[rt][1], 1);
    maintain(rt, 0);
    maintain(rt, 1);
}

void insert(int &rt, int val)
{
    if (rt == 0) {
        rt = ++tails;
        datas[rt] = val;
        son[rt][0] = son[rt][1] = 0;
        siz[rt] = 1;
        return ;
    }
    ++siz[rt];
    if (val <= datas[rt])
        insert(son[rt][0], val);
    else
        insert(son[rt][1], val);
    maintain(rt, datas[rt] > val);
}

void del(int &rt, int val)
{
    if (datas[rt] != val) {
        del(son[rt][datas[rt] < val], val);
        siz[rt] = siz[son[rt][0]] + siz[son[rt][1]] + 1;
        return ;
    }
    --siz[rt];
    if (son[rt][0] == 0)
        rt = son[rt][1];
    else if (son[rt][1] == 0)
        rt = son[rt][0];
    else {
        int p = son[rt][1];
        while (son[p][0] != 0)
            p = son[p][0];
        datas[rt] = datas[p];
        del(son[rt][1], datas[p]);
    }
}

int pre (int val)
{
    int cur = sbt, ans = 0;
    while (cur != 0) {
        if (datas[cur] < val)
            ans = cur, cur = son[cur][1];
        else
            cur = son[cur][0];
    }
    return datas[ans];
}

int nxt (int val)
{
    int cur = sbt, ans = 0;
    while (cur != 0) {
        if (datas[cur] > val)
            ans = cur, cur = son[cur][0];
        else
            cur = son[cur][1];
    }
    return datas[ans];
}

int xth(int x)
{
    int cur = sbt;
    while (siz[son[cur][0]] + 1 != x) {
        if (siz[son[cur][0]] + 1 < x)
            x -= (siz[son[cur][0]] + 1), cur = son[cur][1];
        else
            cur = son[cur][0];
    }
    return datas[cur];
}

int ranks(int rt,int val)
{
    if (!rt) return 1;
    int cur = rt, ans = 0;
        if (datas[cur] < val)
            ans += (siz[son[cur][0]] + 1), ans+=ranks(son[cur][1],val);
        else
            ans+=ranks(son[cur][0],val);
    return ans;
}

int main()
{
    int n;
    n = read();
    for (int i = 1; i <= n; ++i) {
        int op = read(), x = read();
        if (op == 1)
            insert(sbt,x);
        if (op == 2)
            del(sbt,x);
        if (op == 3)
            cout << ranks(sbt,x) << endl;
        if (op == 4)
            cout << xth(x) << endl;
        if (op == 5)
            cout << pre(x) << endl;
        if (op == 6)
            cout << nxt(x) << endl;
    }
    return 0;
}