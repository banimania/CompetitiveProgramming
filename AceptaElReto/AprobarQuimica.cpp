#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  const vector<string> orden = {"1s", "2s", "2p", "3s", "3p", "4s", "3d", "4p", "5s", "4d", "5p", "6s", "4f", "5d", "6p", "7s", "5f", "6d", "7p"};
  unordered_map<char, int> maxE = {
    {'s', 2},
    {'p', 6},
    {'d', 10},
    {'f', 14}
  };

  string name;
  int z;
  while (cin >> name) {
    if (name == "Exit") break;
    cin >> z;

    if (z == 0) {
      cout << "1s0\n";
      continue;
    }
    int curr = 0;
    int rem = z;

    while (rem > 0) {
      char orb = orden[curr][1];
      int take = 2;
      if (orb == 'p') take = 6;
      else if (orb == 'd') take = 10;
      else if (orb == 'f') take = 14;
      int now = min(rem, take);

      rem -= now;
      cout << orden[curr] << now << (rem > 0 ? " " : "");
      curr++;
    }

    cout << '\n';
  }
}
