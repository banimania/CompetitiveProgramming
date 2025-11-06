#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll MOD = 1000000009;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int c;
  cin >> c;
  
  while (c--) {
    int e, a, b;
    cin >> e >> a >> b;

    priority_queue<int, vector<int>, function<bool(const int &, const int &)>> pqSmaller([](const int &x, const int &y) {
      return x > y;
    });
    priority_queue<int, vector<int>, function<bool(const int &, const int &)>> pqBigger([](const int &x, const int &y) {
      return x < y;
    });
    ll smSum = 0, bigSum = 0;
    for (int i = 0; i < e; i++) {
      char ch;
      cin >> ch;

      if (ch == 'H') {
        int x;
        cin >> x;

        pqBigger.push(x);
        bigSum = (bigSum + x) % MOD;
        pqSmaller.push(x);
        smSum = (smSum + x) % MOD;

        while (pqBigger.size() > a) {
          bigSum = (MOD + (bigSum - pqBigger.top())) % MOD;
          pqBigger.pop();
        }
        while (pqSmaller.size() > b) {
          smSum = (MOD + (smSum - pqSmaller.top())) % MOD;
          pqSmaller.pop();
        }
      } else if (ch == 'P') {
        cout << (smSum + bigSum) % MOD << "\n";
      }
    }
    cout << "---\n";
  }

  return 0;
}
