//InzamZ
//
#include <bits/stdc++.h>
using namespace std;


class DataStream {
  private:
    int val, k;
    queue<int> q;
    map<int, int> mp;
  public:
    DataStream(int value, int k) {
        val = value;
        this->k = k;
    }

    bool consec(int num) {
        q.push(num);
        mp[num]++;
        if (q.size() > k) {
            mp[q.front()]--;
            q.pop();
        }
        if (q.size() == k) {
            if (mp[val] == k) return true;
        }
        return false;
    }
};


int main() {
    DataStream sol(4,3);
    return 0;
}