#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int tt;
  cin >> tt;
  for (int t = 1; t <= tt; t++) {
    int n, k, p;
    cin >> n >> k >> p;

    k--;

    cout << "Case " << t << ": " << (k + p) % n + 1 << endl;
  }
  return 0;
}
