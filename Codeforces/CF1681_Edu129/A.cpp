//InzamZ
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define f(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define F(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0)
#define FFFOUT freopen("./out.txt" , "w", stdout)
#define FFFIN freopen("./in.txt" , "r", stdin)
const int maxn = 5e5 + 10;
const int maxb = 110;
int T = 1, n, m, x, ans = 0, a[maxn], b[maxn];
vector<int>e[maxn], v;
string s;

int solve() {
    priority_queue<int>pa, pb, qa, qb;
    ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        qa.push(a[i]);
        pa.push(a[i]);
    }
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        qb.push(b[i]);
        pb.push(b[i]);
    }
    int flag = 1,cnt = 0;
    while (1) {
        while (!qa.empty() && qa.top() <= cnt) {
            qa.pop();
        }
        if (qa.empty()) {
            flag = 2;
            break;
        }
        else {
            cnt = qa.top();
            qa.pop();
        }
        while (!qb.empty() && qb.top() <= cnt) {
            qb.pop();
        }
        if (qb.empty()) {
            flag = 1;
            break;
        }
        else {
            cnt = qb.top();
            qb.pop();
        }
    }
    if (flag == 1) {
        cout << "Alice\n";
    }
    else {
        cout << "Bob\n";
    }
    cnt = 0;
    while (1) {
        while (!pb.empty() && pb.top() <= cnt) {
            pb.pop();
        }
        if (pb.empty()) {
            flag = 1;
            break;
        }
        else {
            cnt = pb.top();
            pb.pop();
        }
        while (!pa.empty() && pa.top() <= cnt) {
            pa.pop();
        }
        if (pa.empty()) {
            flag = 2;
            break;
        }
        else {
            cnt = pa.top();
            pa.pop();
        }
    }
    if (flag == 1) {
        cout << "Alice\n";
    }
    else {
        cout << "Bob\n";
    }
    return 0;
}

signed main() {
    FIO;
    cin >> T;
    while (T--) {
        // cout << "Case #" << T + 1 << ":" << endl;
        solve();
    }
    return 0;
}