//InzamZ

#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long t, d, k, num;
    scanf ("%lld", &t);
    while (t--) {
        scanf ("%lld %lld", &d, &k);
        for ( num = k ; 2 * num * num <= d * d ; num += k );
        num -= k;
        if ( num * num + (num + k) * (num + k) > d * d )
            printf("Utkarsh\n");
        else
            printf("Ashish\n");
    }
    return 0;
}