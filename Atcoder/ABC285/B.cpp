// Created on Inzam的iPad.

#include <iostream>
using namespace std;

string s;
int n;

int main() {
    cin >> n >> s;
    s = " " + s;
    for (int i = 1; i < n; ++i)
    {
        int ans = 0;
        for (int j = 1; j + i<= n; ++j)
        {
            // cout << "aaa: " << s[j] << " " << s[j + i] << " " << '\n';
            if (s[j] == s[j + i])
            {
                ans = j - 1;
                break;
            }
            if (j + i == n) 
            {
                ans = j;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}