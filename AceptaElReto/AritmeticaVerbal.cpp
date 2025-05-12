// TODO: fixear TLE :(

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string solve(string &p1, string &p2, string &p3, char &simb, vector<bool> &used) {
  if (p1[0] == '0' || p2[0] == '0' || p3[0] == '0') return "";

  char curr = 'X';
  for (int i = 0; i < p1.size(); i++) {
    if (isalpha(p1[i])) {
      curr = p1[i];
      break;
    }
  }
  if (curr == 'X') {
    for (int i = 0; i < p2.size(); i++) {
      if (isalpha(p2[i])) {
        curr = p2[i];
        break;
      }
    }
  }
  if (curr == 'X') {
    for (int i = 0; i < p3.size(); i++) {
      if (isalpha(p3[i])) {
        curr = p3[i];
        break;
      }
    }
  }

  if (curr == 'X') {
    ll n1 = stoll(p1), n2 = stoll(p2), n3 = stoll(p3);

    if (simb == '+') {
      if (n1 + n2 == n3) {
        return string(p1 + " + " + p2 + " = " + p3);
      } else return "";
    } else {
      if (n1 * n2 == n3) {
        return string(p1 + " * " + p2 + " = " + p3);
      } else return "";
    }

  } else {
    for (int i = 0; i <= 9; i++) {
      if (!used[i]) {
        used[i] = true;

        for (int j = 0; j < p1.size(); j++) {
          if (p1[j] == curr) {
            p1[j] = i + '0';
          }
        }
        
        for (int j = 0; j < p2.size(); j++) {
          if (p2[j] == curr) {
            p2[j] = i + '0';
          }
        }

        for (int j = 0; j < p3.size(); j++) {
          if (p3[j] == curr) {
            p3[j] = i + '0';
          }
        }

        string ans = solve(p1, p2, p3, simb, used);
        if (!ans.empty()) return ans;

        for (int j = 0; j < p1.size(); j++) {
          if (p1[j] == i + '0') {
            p1[j] = curr;
          }
        }
        
        for (int j = 0; j < p2.size(); j++) {
          if (p2[j] == i + '0') {
            p2[j] = curr;
          }
        }

        for (int j = 0; j < p3.size(); j++) {
          if (p3[j] == i + '0') {
            p3[j] = curr;
          }
        }

        used[i] = false;
      }
    }
  }
  return "";
}

int main() {
  char simb, eq;
  string p1, p2, p3;
  while (cin >> p1 >> simb >> p2 >> eq >> p3) {
    vector<bool> used(10);
    cout << solve(p1, p2, p3, simb, used) << endl;
  }
  return 0;
}
