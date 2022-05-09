#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
using ll = long long;

struct node {
    int val, l, r;
    int ls, rs;
} Tree[maxn << 6];

int a[maxn], b[maxn], ida[maxn], idb[maxn];
map<int,int>mpa,mpb;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M, K;
    cin >> N;
    mpa.clear();
    mpb.clear();
    for (int i = 0; i <= N; ++i) ida[i] = idb[i] = 0;	
    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
        mpb[a[i]] = mpa[a[i]] = N + 1;
    }
    for (int i = 1; i <= N; ++i) {
        cin >> b[i];
        mpa[b[i]] = mpb[b[i]] = N + 1;
    }
    for (int i = 1; i <= N; ++i)
    {
        if (mpa[a[i]] == N + 1) mpa[a[i]] = i;
        if (mpb[b[i]] == N + 1) mpb[b[i]] = i;
    }
    for (int i = 1; i <= N; ++i){
        ida[i] = max(ida[i - 1], mpb[a[i]]);
        //cout << ida[i] << ' ';
    }
    for (int i = 1; i <= N; ++i){
        // cout << mpa[b[i]] << ' ' << idb[i-1] << ' ';
        idb[i] = max(idb[i - 1], mpa[b[i]]);
        // cout << idb[i] << '\n';
    }
    cin >> M ;
    for (int i = 1; i <= M; ++i) {
        int qa, qb;
        cin >> qa ;
        cin >> qb ;
        if (ida[qa] <= qb && idb[qb] <= qa)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}