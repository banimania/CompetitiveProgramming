#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a, b;
  while (cin >> a >> b) {
    // queue<int> q;
    unordered_set<int> s;

    int resto = a * 10;
    // int del = 0;

    while (resto != 0) {
      if (s.count(resto)) {
        break;
      }

      s.insert(resto);
      // q.push(resto / b);

      resto = (resto - (b * (resto / b))) * 10;
    }
    int del = resto;
    bool flag = false;
    // cout << a << "/" << b << ": ";
    cout << "0.";
    resto = a * 10;
    while (resto != 0) {
      if (resto == del && !flag) {
        cout << "|";
        flag = true;
      } else if (resto == del && flag) {
        break;
      }
      cout << resto/b;
      resto = (resto - (b * (resto / b))) * 10;
    }
    // while (!q.empty()) {
    //   int num = q.front();
    //   q.pop();

    //   if (num == del && !flag) {
    //     flag = true;
    //     cout << "|";
    //   }
    //   cout << num;
    // }
    cout << (flag ? "|\n" : "\n");
  }
  return 0;
}
