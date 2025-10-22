#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    string mStr1, mStr2;
    cin >> mStr1 >> mStr2;

    int nCamp, q;
    cin >> nCamp >> q;

    int h1 = stoi(mStr1.substr(0, 2));
    int m1 = stoi(mStr1.substr(3, 2));
    int s1 = stoi(mStr1.substr(6, 2));

    int mom1 = h1 * 60 * 60 + m1 * 60 + s1;

    int h2 = stoi(mStr2.substr(0, 2));
    int m2 = stoi(mStr2.substr(3, 2));
    int s2 = stoi(mStr2.substr(6, 2));

    int mom2 = h2 * 60 * 60 + m2 * 60 + s2;

    int t = mom2 - mom1;
    if (mom1 > mom2) {
      t = 24 * 60 * 60 - mom1 + mom2;
    }

    int dt = t / (nCamp - 1);
    int ans = (mom1 + dt * (q - 1)) % (24 * 60 * 60);

    int ansH = (ans / 60) / 60;
    int ansM = (ans / 60) % 60;
    int ansS = ans % 60;

    cout << setw(2) << setfill('0') << ansH << ":" << setw(2) << setfill('0') << ansM << ":" << setw(2) << setfill('0') << ansS << "\n";
  }
  return 0;
}
