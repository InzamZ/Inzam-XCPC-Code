// Created on Inzam的iPad.

#include <iostream>
#include <map>
#include <queue>
using namespace std;

#define maxn 200010
string s1, s2;
int n, ans = 0, id = 1;
int outdeg[maxn], pa[maxn];
queue<int>q;
map<string, int>mp;

int main() {
    cin >> n;
    for (int i = 0 ; i < n; ++i) {
        cin >> s1 >> s2;
        if (mp.count(s1) == 0)
            mp[s1] = id++;
        if (mp.count(s2) == 0)
            mp[s2] = id++;
        outdeg[mp[s1]]++;
        pa[mp[s2]] = mp[s1];
    }
    for (int i = 1; i < id; ++i) {
        if (outdeg[i] == 0)
            q.push(i);
    }
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        if (--outdeg[pa[cur]] == 0)
            q.push(pa[cur]);
    }
    for (int i = 1; i < id; ++i)
        ans |= outdeg[i];
    if (ans == 0)
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}