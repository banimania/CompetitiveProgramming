#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  vector<bool> f(a.size() + 1, 0);
  for (int i = 0; i < n; i++) {
    if (a[i] <= a.size()) f[a[i]] = 1;
  }
  int mex = 0;
  while (f[mex]) mex++;


  int cnt = 0;
  int aux = k % (n + 1);

  for (int i = 0; i < aux - 1; i++) {
    cout << a[n - aux + 1 + i] << " ";
    cnt++;
  }
  
  if (aux != 0) {
    cout << mex << " ";
    cnt++;
  }

  for (int i = 0; i < n - cnt; i++) {
    cout << a[i] << " ";
  }

  cout << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
