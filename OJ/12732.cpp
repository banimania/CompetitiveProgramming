#include <bits/stdc++.h>
using namespace std;

int test(int l, int r) {
  cout << "Test";
  for (int i = l; i <= r; i++) {
    cout << " " << i;
  }
  cout << endl << flush;

  int ans;
  cin >> ans;

  return ans;
}

void solve(int l, int r) {
  int n = r - l + 1;
  // cout << "Solve(" << l << ", " << r << ")" << endl;
  // cout << n << endl;

  if (n == 2) {
    int ans = test(l, r);
    cout << "Answer " << (ans == 1 ? l : r) << endl << flush;
    return;
  } else if (n == 3) {
    int ans = test(l, r - 1);
    if (ans == 0) {
      cout << "Answer " << r << endl << flush;
    } else {
      cout << "Answer " << (ans == 1 ? l : r - 1) << endl << flush;
    }
    return;
  }

  if (n % 2) {
    int ans = test(l, r - 1);

    int bajo, alto;
    if (ans == 0) {
      cout << "Answer " << r << endl << flush;
      return;
    } else if (ans == 1) {
      bajo = l;
      alto = l + (n - 1) / 2 - 1;
    } else {
      bajo = l + (n - 1) / 2;
      alto = r - 1;
    }

    solve(bajo, alto);
  } else {
    int ans = test(l, r);

    int bajo, alto;
    if (ans == 1) {
      bajo = l;
      alto = (l + r) / 2;
    } else {
      bajo = (l + r) / 2 + 1;
      alto = r;
    }

    solve(bajo, alto);
  }
}

void solve() {
  int n;
  cin >> n;

  solve(1, n);
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) solve();
  return 0;
}
