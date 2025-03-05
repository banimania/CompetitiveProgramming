#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  while (cin >> n && n) {
    map<int, int> freq;

    int maxFreq = 0;
    int moda = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      freq[x]++;

      if (freq[x] > maxFreq) {
        moda = x;
        maxFreq = freq[x];
      }
    }

    cout << moda << endl;
  }
  return 0;
}
