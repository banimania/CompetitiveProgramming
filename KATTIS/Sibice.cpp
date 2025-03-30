#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, w, h;
  cin >> n >> w >> h;

  double maxLength = sqrt(w * w + h * h);
  for (int i = 0; i < n; i++) {
    int l;
    cin >> l;

    cout << (l > maxLength ? "NE" : "DA") << endl;
  }
  return 0;
}
