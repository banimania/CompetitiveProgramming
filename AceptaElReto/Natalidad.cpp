#include <bits/stdc++.h>
using namespace std;

#define TESTCASES false 

void getChilds(int &index, string &s, bool &cumple1, bool &cumple2) {
  char actual = s[index];
  if (actual == '.') return;

  index++;
  if (index >= s.size()) return;
  char h1 = s[index];
  getChilds(index, s, cumple1, cumple2);
  index++;
  if (index >= s.size()) return;
  char h2 = s[index];
  getChilds(index, s, cumple1, cumple2);


  if ((h1 != '.' && h2 != '.')) cumple1 = false;
  if (((h1 != '.' && h2 == '.') || (h1 == '.' && h2 != '.')) && (h1 != '.' || h2 != '.')) cumple2 = false;
}

void solve() {
  string s;
  while (cin >> s && s != ".") {
    bool cumple1 = true, cumple2 = true;
    int index = 0;

    getChilds(index, s, cumple1, cumple2);

    string ans = (cumple1 ? "1" : "");
    ans += (cumple2 ? "2" : "");
    cout << (ans.empty() ? "N" : ans) << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;

  if (TESTCASES) cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
