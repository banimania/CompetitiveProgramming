#include <iostream>
#include <set>
#include <vector>

#define ll long long

using namespace std;

void solve() {
  ll n;
  cin >> n;

  ll a[n];
  for (ll i = 0; i < n-1; i++) {
    cin >> a[i];
  }

  set<ll> s;
  ll excedent = 0;
  for (ll i = 0; i < n-1; i++) {
    if (i == 0) {
      if (a[i] > n) {
        excedent = a[i];
        continue;
      }
      s.insert(a[i]);
      continue;
    }

    if (a[i] - a[i-1] > n) {
      if (excedent != 0) {
        cout << "NO\n";
        return;
      }
      excedent = a[i] - a[i-1];
      continue;
    }
    bool inserted = s.insert(a[i] - a[i-1]).second;
    if (!inserted) {
      if (excedent != 0) {
        cout << "NO\n";
        return;
      }
      excedent = a[i] - a[i-1];
    }
  }

  vector<ll> missing;
  for (ll i = 1; i <= n; i++) {
    if (s.find(i) == s.end()) {
      missing.push_back(i);
    }
  }

  if (missing.size() == 1 && excedent == 0) {
    cout << "YES\n";
    return;
  } else if (missing.size() == 1 && excedent != 0) {
    cout << "NO\n";
    return;
  } else if (missing.size() == 2 && excedent == 0) {
    cout << "NO\n";
    return;
  } else if (missing.size() == 2 && excedent != 0) {
    if (missing[0] + missing[1] == excedent) {
      cout << "YES\n";
      return;
    } else {
      cout << "NO\n";
      return;
    }
  } else if (missing.size() > 2) {
    cout << "NO\n";
    return;

  }

  cout << "NO\n";

  return;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
