#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string var, req;
  while (cin >> var >> req) {
    vector<string> words;
    string cur = "";

    for (int i = 0; i < (int)var.size(); i++) {
      char c = var[i];
      if (c == '_' || c == '-') {
        if (!cur.empty()) {
          words.push_back(cur);
          cur.clear();
        }
      } else if (isupper(c)) {
        if (!cur.empty()) {
          words.push_back(cur);
          cur.clear();
        }
        cur += tolower(c);
      } else {
        cur += c;
      }
    }
    if (!cur.empty()) words.push_back(cur);

    string ans;
    if (req == "CamelCase") {
      for (auto &w : words) {
        w[0] = toupper(w[0]);
        ans += w;
      }
    } else if (req == "snake_case") {
      for (int i = 0; i < (int)words.size(); i++) {
        if (i) ans += "_";
        ans += words[i];
      }
    } else if (req == "kebab-case") {
      for (int i = 0; i < (int)words.size(); i++) {
        if (i) ans += "-";
        ans += words[i];
      }
    }

    cout << ans << "\n";
  }
}
