#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
int tri[1000005][3], ans[1000005], fa[1000005], line_id, map2len, T, n;
map<pair<int, int>, int>line_hash;
map<int, int>map2;

int findfa(int x) {
    if (fa[x] == x)
        return x;
    return fa[x] = findfa(fa[x]);
}
int merge(int x, int y) {
    int fx = findfa(x);
    int fy = findfa(y);
    if (fx == fy)
        return 0;
    fa[fx] = fy;
    return 1;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i <= 3 * n; i++)
            fa[i] = i;
        line_hash.clear(); map2.clear();
        line_id = map2len = 0;
        pair<int, int> line1, line2, line3;
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < 3; k++)
                scanf("%d", &tri[i][k]);
            sort(tri[i], tri[i] + 3);
            line1.first = tri[i][0], line1.second = tri[i][1];
            if (line_hash.count(line1) == 0)
                line_hash[line1] = ++line_id;
            line2.first = tri[i][0], line2.second = tri[i][2];
            if (line_hash.count(line2) == 0)
                line_hash[line2] = ++line_id;
            line3.first = tri[i][1], line3.second = tri[i][2];
            if (line_hash.count(line3) == 0)
                line_hash[line3] = ++line_id;
            merge(line_hash[line1], line_hash[line2]);
            merge(line_hash[line1], line_hash[line3]);
        }
        for (int i = 1; i <= line_id; i++)
            fa[i] = findfa(i);
        for (int i = 0; i < n; i++) {
            line1.first = tri[i][0], line1.second = tri[i][1];
            int f = findfa(line_hash[line1]);
            if (map2.count(f) == 0) {
                map2[f] = map2len++;
                ans[map2[f]] = 0;
            }
            ans[map2[f]]++;
        }
        sort(ans, ans + map2len);
        printf("%d\n", map2len);
        for (int i = 0; i < map2len; i++)
            printf("%d ", ans[i]);
        printf("\n");
    }
    return 0;
}