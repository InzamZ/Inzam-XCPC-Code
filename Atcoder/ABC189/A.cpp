#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int inf = 1e9 + 7;
const int maxn = 1e6;

int main()
{
    char a, b, c;
    scanf("%c%c%c", &a, &b, &c);
    if (a == b && b == c)
        printf("Won\n");
    else
        printf("Lost\n");
    return 0;
}