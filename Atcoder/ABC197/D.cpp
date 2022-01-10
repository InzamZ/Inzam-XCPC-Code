#include <bits/stdc++.h>
using namespace std;

const double pai = 3.14159265358979323846;
#define P (2*pai/n)

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    double n, a, b, c, d, ox, oy, ansx, ansy;
    cin >> n >> a >> b >> c >> d;
    ox = (a + c) / 2;
    oy = (b + d) / 2;
    ansx = ox + (a - ox) * cos(P) - (b - oy) * sin(P);
    ansy = oy + (a - ox) * sin(P) + (b - oy) * cos(P);
    cout << fixed << setprecision(15) << ansx;
    cout << ' ';
    cout << fixed << setprecision(15) << ansy;
    return 0;
}