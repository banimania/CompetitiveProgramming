#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  while (cin >> n && n) {
    vector<int> a(n);
    vector<int> positivos, negativos;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] > 0) positivos.push_back(a[i]);
      else negativos.push_back(a[i]);
    }
    sort(positivos.begin(), positivos.end(), [](const int &x, const int &y) {
      return x < y;
    });
    sort(negativos.begin(), negativos.end(), [](const int &x, const int &y) {
      return x > y;
    });

    int posIndex = 0, negIndex = 0;
    for (int i = 0; i < a.size(); i++) {
      if (a[i] > 0) {
        a[i] = positivos[posIndex];
        posIndex++;
      } else {
        a[i] = negativos[negIndex];
        negIndex++;
      }
    }

    for (int i = 0; i < a.size(); i++) {
      cout << a[i] << (i != a.size() - 1 ? " " : "");
    }
    cout << endl;
  }
  return 0;
}
