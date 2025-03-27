#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  vector<string> ans;
  while (getline(cin, s)) ans.push_back(s);

  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << endl;
  }
  return 0;
}
