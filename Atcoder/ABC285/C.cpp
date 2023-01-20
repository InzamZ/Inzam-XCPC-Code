// Created on Inzam的iPad.

#include <iostream>
using namespace std;

string s;
long long n = 0;

int main() {
    cin >> s;
    int len = s.length();
    for (int i = 0 ; i < len; ++i)
    {
        n = n * 26 + s[i] - 'A' + 1;
    }
    cout << n << endl;
    return 0;
}