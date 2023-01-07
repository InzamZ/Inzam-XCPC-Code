//InzamZ
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string categorizeBox(int length, int width, int height, int mass) {
        bool b = 0, c = 0;
        if (length >= 10000 || width >= 10000 || height >= 10000 || 1ll * length * width * height >= 1000000000)
            b = 1;
        if (mass >= 100)
            c = 1;
        if (b && c) return "Both";
        else if (b) return "Bulky";
        else if (c) return "Heavy";
        else return "Neither";
    }
};

int main() {
    Solution sol;
    return 0;
}