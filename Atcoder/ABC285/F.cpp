#include <atcoder/all>
#include <bits/stdc++.h>

using namespace atcoder;
using namespace std;

int n, a, b, c, q;
string s, s1;
vector< fenwick_tree<int> > cnt;
int alpha[30];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin >> n >> s >> q;
    s = " " + s;
    fenwick_tree<int> ord(n + 1);
    for (int i = 0; i < 26; ++i) {
        cnt.push_back(fenwick_tree<int>(n + 1));
        alpha[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        cnt[s[i] - 'a'].add(i, 1);
        alpha[s[i] - 'a']++;
        if (i == n)
            continue;
        if (s[i + 1] >= s[i])
            ord.add(i, 1);
    }
    s[0] = '\0';
    for (int i = 1; i <= q; ++i) {
        cin >> a >> b;
        if (a == 1) {
            cin >> s1;
            alpha[s[b] - 'a']--;
            cnt[s[b] - 'a'].add(b, -1);
            if (b != 1 && s[b] >= s[b - 1] && s1[0] < s[b - 1])
                ord.add(b - 1, -1);
            if (b != 1 && s[b] < s[b - 1] && s1[0] >= s[b - 1])
                ord.add(b - 1, 1);
            if (s[b + 1] >= s[b] && s[b + 1] < s1[0])
                ord.add(b, -1);
            if (s[b + 1] < s[b] && s[b + 1] >= s1[0])
                ord.add(b, 1);
            alpha[s1[0] - 'a']++;
            cnt[s1[0] - 'a'].add(b, 1);
            s[b] = s1[0];
        }
        else {
            bool ans = 1;
            cin >> c;
            if (ord.sum(b, c) != c - b)
                ans = 0;
            // cout << "order " << ord.sum(b, c) << " " << c - b << '\n';
            for (int j = s[b] - 'a' + 1; j < s[c] - 'a'; ++j) {
                if (cnt[j].sum(b, c + 1) != alpha[j])
                    ans = 0;
                // cout << "cnt vs alpha " << j << " " << cnt[j].sum(b, c + 1) << " " << alpha[j] << '\n';
            }
            if (ans)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
    return 0;
}