#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int n;
  cin >> n;

  multiset<int, greater<int>> a, b;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a.insert(x);
  }

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    b.insert(x);
  }

  bool turnA = true;
  ll A = 0, B = 0;

  while (!a.empty() || !b.empty()) {
    if (turnA) {
      if (a.empty()) {
        b.erase(b.begin());
      } else {
        if (*a.begin() > *b.begin()) {
          A += *a.begin();
          a.erase(a.begin());
        } else {
          b.erase(b.begin());
        }
      }
    } else {
      if (b.empty()) {
        a.erase(a.begin());
      } else {
        if (*b.begin() > *a.begin()) {
          B += *b.begin();
          b.erase(b.begin());
        } else {
          a.erase(a.begin());
        }
      }
    }
    turnA = !turnA;
  }

  cout << A - B << endl;
  return 0;
}
