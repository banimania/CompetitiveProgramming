#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct City {
  ll x, y, people;
  double dist;
};

int main() {
  ll n, s;
  cin >> n >> s;

  vector<City> cities(n);
  for (int i = 0; i < n; i++) {
    cin >> cities[i].x >> cities[i].y >> cities[i].people;
    cities[i].dist = sqrt(pow(cities[i].x, 2) + pow(cities[i].y, 2));
  }

  sort(cities.begin(), cities.end(), [](const City &a, const City &b) {
    if (a.dist == b.dist) return a.people > b.people;
    return a.dist < b.dist;
  });

  ll neededPeople = 1000000 - s;

  ll cnt = 0;
  for (int i = 0; i < n; i++) {
    cnt += cities[i].people;

    if (cnt >= neededPeople) {
      cout << fixed << setprecision(7) << cities[i].dist << endl;
      return 0;
    }
  }

  cout << -1 << endl;

  return 0;
}
