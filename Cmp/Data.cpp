#include <cstdio>
#include <cstdlib>
#include <ctime>
int main() {
    freopen("data.input", "w", stdout);
    srand(time(0));
    int n = rand() % 10;
    printf("%d\n", n);
    for (int i = 0; i < n ; ++i)
        printf("%d ", rand() % 20) ;
    putchar('\n');
    return 0;
}
