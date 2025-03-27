#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  map<string, string> bdayFriend;
  map<string, int> likeness;
  for (int i = 0; i < n; i++) {
    string name, bday;
    int c;

    cin >> name >> c >> bday;

    likeness[name] = c;

    if (!bdayFriend.count(bday)) bdayFriend[bday] = name;
    else {
      int cfriend = likeness[bdayFriend[bday]];

      if (c > cfriend) bdayFriend[bday] = name;
    }
  }

  vector<string> sol;
  for (auto [bday, name] : bdayFriend) {
    sol.push_back(name);
  }
  sort(sol.begin(), sol.end());

  cout << sol.size() << endl;
  for (int i = 0; i < sol.size(); i++) {
    cout << sol[i] << endl;
  }
  return 0;
}
