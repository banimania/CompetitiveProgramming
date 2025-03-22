#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ll n, k;
  cin >> n >> k;

  vector<ll> sums(n - 1);
  ll orAns, andAns;
  for (int i = 0; i < n - 1; i++) {
    cout << "or 1 " << i + 2 << endl;
    cin >> orAns;
    cout << "and 1 " << i + 2 << endl;
    cin >> andAns;

    sums[i] = orAns + andAns;
  }

  cout << "or 2 3" << endl;
  cin >> orAns;
  cout << "and 2 3" << endl;
  cin >> andAns;
  ll twoPlusThree = orAns + andAns;

  ll a1 = -0.5 * (twoPlusThree - sums[1] - sums[0]);

  vector<int> a(n);
  a[0] = a1;
  for (int i = 1; i < n; i++) {
    a[i] = sums[i - 1] - a[0];
  }

  sort(a.begin(), a.end());

  cout << "finish " << a[k - 1] << endl;

  return 0;
}
