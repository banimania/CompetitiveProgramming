#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool solve(ll a, ll b) {
  if (a % 60 != 0) {
    return false;
  }
  int horas = b * 2 / 600;

  int minutos = (b * 2) % 600 / 10;

  if (minutos == a / 60) {
    if (horas < 10) cout << 0;
    cout << horas;

    cout << ":";
    if (minutos < 10) cout << 0;
    cout << minutos << "\n";
    return true;
  } else {
    return false;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    double aIn, bIn;
    cin >> aIn >> bIn;

    int a = aIn * 10, b = bIn * 10;

    if (b % 5 != 0 || a % 5 != 0) {
      cout << "ERROR\n";
      continue;
    }

    if (!solve(a, b)) {
      swap(a, b);
      if (!solve(a, b)) {
        cout << "ERROR\n";
      }
    }

  }

  return 0;
}
