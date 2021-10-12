#include <iostream>
#include <ctime>
using namespace std;

#define RMAXN 200

bool vis[110];

int main()
{
    freopen("data.in", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    srand(time(NULL));
    // cout << 1 << '\n';
    int num1 = rand() % (int)(RMAXN) + 1;
    // num1 = (RMAXN);
    cout << num1 << '\n';
    // int num2 = rand() % (int)(RMAXN) + 1;
    // // num2 = (RMAXN);
    // cout << num2 << ' ';
    // int num3 = rand() % (int)(RMAXN) + 1;
    // cout << num3 << '\n';
    for (int i = 1; i <= num1; ++i)
        cout << rand() % (int)(RMAXN) + 2 << ' ';
    // cout << '\n';
    // for (int j = 1; j <= num3; ++j) {
    //     int a = rand() % (int)(num1) + 1, b = rand() % (int)(num1) + 1, c = rand() % (int)(4) + 2;
    //     while (b < a)
    //         b = rand() % (int)(num1) + 1;
    //     cout << a << ' ' << b << ' ' << c << '\n';
    // }
    // for (int i = 0; i < num1; ++i) {
    //     for (int j = 0; j < num1; ++j) {
    //         if (imap[i][j])
    //             cout << '1';
    //         else
    //             cout << '0';
    //     }
    //     cout << '\n';
    // }
    // num2 = rand() % (int)(RMAXN) + 1;
    // for (int i = 1; i <= num2 * 2; ++i) {
    //     int a = rand() % (int)(num1), b = rand() % (int)(num1);
    //     if (a != b) {
    //         imap2[a][b] = 1;
    //         imap2[b][a] = 1;
    //     }
    // }
    // for (int i = 0; i < num1; ++i) {
    //     for (int j = 0; j < num1; ++j) {
    //         if (imap2[i][j])
    //             cout << '1';
    //         else
    //             cout << '0';
    //     }
    //     cout << '\n';
    // }
    // cout<<num2<<'\n';
    // for (int i = 1; i <= num1; ++i)
    //     cout << rand() % (int)(RMAXN) + 1 << ' ';
    // cout << '\n';
    // for (int i=1;i<=num2;i++) {
    //     int op=rand()% (int)(4)+1;
    //     int x=rand()% (int)(num1)+1,y=rand()% (int)(num1)+1;
    //     while (x==y) y=rand()% (int)(num1)+1;
    //     if (x>y) swap(x,y);
    //     if (op!=4 )cout<<op<<' '<<x<<' '<<y<<'\n';
    //     else cout<<op<<'\n';
    // }
    fclose(stdin);
    return 0;
}