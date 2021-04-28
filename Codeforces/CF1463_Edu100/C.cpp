#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

#define maxn 200010
const long long inf = 1ll << 60;
typedef long long ll;

struct com {
    ll tim, tar;
    com() {}
    com(int a, int b): tim(a), tar(b) {}
    bool operator< (const com x) const
    {
        return tim < x.tim;
    }
};

bool cmp(const com a, const com b)
{
    return a.tim < b.tim;
}

vector <com> s ;

int main()
{
    int T, n;
    scanf("%d", &T);
    while (T--) {
        ll nowt = 0, overt = 0, ans = 0, target = 0, pos = 0;
        bool dir = true;
        com c;
        s.clear();
        scanf("%d", &n);
        for (int i = 0; i < n; i++)   {
            scanf("%lld %lld", &c.tim, &c.tar);
            s.push_back(c);
        }
        for (int i = 0; i < n; i++) {
            ll t1, t2, L, R;
            if (s[i].tim >= overt) {
                nowt = s[i].tim;
                pos = target;
                target = s[i].tar;
                if (pos - s[i].tar > 0)
                    dir = false;
                else
                    dir = true;
                overt = nowt + abs(pos - s[i].tar);
            }
            t1 = s[i].tim;
            if (i != n - 1)
                t2 = s[i + 1].tim;
            else
                t2 = inf;
            if (dir)
                L = pos + (t1 - nowt), R = pos + (t2 - nowt);
            else
                L = pos - (t2 - nowt), R = pos - (t1 - nowt);
            if (R > target && dir)
                R = target;
            if (L > target && dir)
                L = target;
            if (R < target && !dir)
                R = target;
            if (L < target && !dir)
                L = target;
            if ( L <= s[i].tar && s[i].tar <= R )
                ans++;
        }
        printf("%lld\n", ans);
    }
    return 0;
}