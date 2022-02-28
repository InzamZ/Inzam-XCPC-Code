//InzamZ
#include <bits/stdc++.h>
using namespace std;

#define F(i,b,n)  for(int i=(b);i<(n);i++)
#define f(i,b,n)  for(int i=(b);i<=(n);i++)
typedef long long ll;
const char *turns = "FLR";
const char *dires = "ESWN";
#define INF 1e17

int dx[] = {1, 0, -1, 0}; //传统的坐标系变换
int dy[] = {0, -1, 0, 1};

int dr[] = {1, 0, -1, 0}; //行列变化
int dc[] = {0, -1, 0, 1};
ll num1[100010], num2[100010];


int main()
{
    int T, n, top1, top2;
    ll mul = 1;
    scanf ("%d", &T);
    while (T--) {
        memset(num1, 0, sizeof(num1));
        memset(num2, 0, sizeof(num2));
        bool flag = false;
        mul = 1;
        top1 = top2 = 0;
        int denum = 0;
        scanf ("%d", &n);
        F(i, 0, n) {
            ll num;
            scanf ("%lld", &num);
            if (num >= 0)
                num1[top1++] = num;
            else
                num2[top2++] = num;
        }
        sort(num1, num1 + top1);
        sort(num2, num2 + top2);
        if (n == 5) {
            f(i, 0, top1 - 1) mul *= num1[i];
            f(i, 0, top2 - 1) mul *= num2[i];
            printf("%lld\n", mul);
            continue;
        }
        if (top1 == 0)
            mul = num2[top2 - 1] * num2[top2 - 2] * num2[top2 - 3] * num2[top2 - 4] * num2[top2 - 5];
        else {
            top1--, top2--;
            int cur1 = top1, cur2 = 0;
            f(i, 1, 5) {
                if ( cur1 < 0 ) {
                    mul *= num2[cur2];
                    cur2++;
                    denum++;
                }
                else if ( cur2 > top2 || abs(num1[cur1]) >= abs(num2[cur2])) {
                    mul *= num1[cur1];
                    cur1--;
                }
                else {
                    mul *= num2[cur2];
                    cur2++;
                    denum++;
                }
            }
            if (denum % 2 == 1) {
                ll mull1 = -1e17, mull2 = -1e17;
                if ( cur2 != 0 && cur1 <= top1 && cur1 >= 0)
                    mull1 = mul / num2[cur2 - 1] * num1[cur1];
                if ( num1[cur1 + 1] != 0 && cur2 <= top2 && cur2 >= 0)
                    mull2 = mul / num1[cur1 + 1] * num2[cur2];
                mul = max(mul, mull1);
                mul = max(mul, mull2);
            }
        }
        printf("%lld\n", mul);
    }
    return 0;
}