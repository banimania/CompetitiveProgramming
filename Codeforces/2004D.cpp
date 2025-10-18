#include <bits/stdc++.h>
using namespace std;

bool canTravel(const string &a, const string &b) {
  return (a[0] == b[0] || a[1] == b[0] || a[0] == b[1] || a[1] == b[1]);
}

void calculateNextColors(unordered_map<string, pair<vector<int>, vector<int>>> &colors, const vector<string> &cities, const string color) {
  vector<int> nextDif(cities.size(), -1);
  vector<int> prevDif(cities.size(), -1);

  for (int i = cities.size() - 1; i >= 0; i--) {
    if (canTravel(cities[i], color) && cities[i] != color) {
      nextDif[i] = i;
    } else {
      nextDif[i] = (i + 1 < cities.size() ? nextDif[i + 1] : -1);
    }
  }

  for (int i = 0; i < cities.size(); i++) {
    if (canTravel(cities[i], color) && cities[i] != color) {
      prevDif[i] = i;
    } else {
      prevDif[i] = (i - 1 >= 0 ? prevDif[i - 1] : -1);
    }
  }

  colors[color] = {nextDif, prevDif};
}


int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    vector<string> cities(n);
    for (int i = 0; i < n; i++) {
      cin >> cities[i];
    }
    unordered_map<string, pair<vector<int>, vector<int>>> colors;
    calculateNextColors(colors, cities, "BG");
    calculateNextColors(colors, cities, "BR");
    calculateNextColors(colors, cities, "BY");
    calculateNextColors(colors, cities, "GR");
    calculateNextColors(colors, cities, "GY");
    calculateNextColors(colors, cities, "RY");

    for (int i = 0; i < q; i++) {
      int x, y;
      cin >> x >> y;
      x--, y--;

      if (canTravel(cities[x], cities[y])) {
        cout << abs(x - y) << endl;
      } else {
        int ans = INT_MAX;

        if (x + 1 < n && colors[cities[x]].first[x + 1] != -1) {
          ans = min(ans, abs(x - colors[cities[x]].first[x + 1]) + abs(y - colors[cities[x]].first[x + 1]));
        }

        if (x - 1 >= 0 && colors[cities[x]].second[x - 1] != -1) {
          ans = min(ans, abs(x - colors[cities[x]].second[x - 1]) + abs(y - colors[cities[x]].second[x - 1]));
        }

        if (ans == INT_MAX) ans = -1;
        cout << ans << endl;
      }
    }

  }

}
