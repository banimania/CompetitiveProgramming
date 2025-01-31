/*
▗▄▄▄  ▗▄▖ ▗▖  ▗▖▗▄▄▄▖▗▖  ▗▖ ▗▄▖ ▗▖  ▗▖▗▄▄▄▖ ▗▄▖ 
▐▌  █▐▌ ▐▌▐▛▚▖▐▌  █  ▐▛▚▞▜▌▐▌ ▐▌▐▛▚▖▐▌  █  ▐▌ ▐▌
▐▌  █▐▛▀▜▌▐▌ ▝▜▌  █  ▐▌  ▐▌▐▛▀▜▌▐▌ ▝▜▌  █  ▐▛▀▜▌
▐▙▄▄▀▐▌ ▐▌▐▌  ▐▌▗▄█▄▖▐▌  ▐▌▐▌ ▐▌▐▌  ▐▌▗▄█▄▖▐▌ ▐▌
*/

#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef vector<ll> vll;
 
#define REP(i, a, b) for (int i = a; i < b; ++i)
#define REPV(i, a, b) for (int i = a; i >= b; --i)
#define SCAN(a) for (int i = 0; i < a.size(); ++i) cin >> a[i]
#define PRINT(a) for (int i = 0; i < a.size(); ++i) { cout << a[i] << " "; }
#define PRINTLN(a) for (int i = 0; i < a.size(); ++i) { cout << a[i] << " "; } cout << endl
#define SORTASC(a) sort(a.begin(), a.end(), [](auto x, auto y) { return x < y; })
#define SORTDESC(a) sort(a.begin(), a.end(), [](auto x, auto y) { return x > y; })
#define FIND(a, target) find(a.begin(), a.end(), target) - a.begin()
#define UPPER(a, target) upper_bound(a.begin(), a.end(), target) - a.begin()
#define LOWER(a, target) lower_bound(a.begin(), a.end(), target) - a.begin()
#define MAX(a) distance(a.begin(), max_element(a.begin(), a.end()))
#define MIN(a) distance(a.begin(), min_element(a.begin(), a.end()))

#define TESTCASES false

// directions
// 0 -> {1, 0}   NORTH
// 1 -> {-1, 0}  SOUTH
// 2 -> {0, 1}   EAST
// 3 -> {0, -1}  WEST

bool hitsAll(vector<vector<char>> &a, pair<ll, ll> start, ll dir, ll mirrorCount) {
  ll mirrorsHit = 0;

  queue<pair<pair<ll, ll>, ll>> queue;
  queue.push({start, dir});

  while (!queue.empty()) {
    pair<pair<ll, ll>, ll> current = queue.front();
    queue.pop();
    pair<ll, ll> pos = current.first;
    ll dir = current.second;
    ll i = pos.first;
    ll j = pos.second;

    if (a[i][j] != '.') mirrorsHit++;
    
    ll newDir = dir;
    if (a[i][j] == '/') {
      if (dir == 1) newDir = 3;
      else if (dir == 0) newDir = 2;
      else if (dir == 2) newDir = 0;
      else if (dir == 3) newDir = 1;
    } else if (a[i][j] == '\\') {
      if (dir == 1) newDir = 2;
      else if (dir == 0) newDir = 3;
      else if (dir == 2) newDir = 1;
      else if (dir == 3) newDir = 0;
    }

    ll newI = i;
    ll newJ = j;

    //cout << i << " " << j << " -> " << newI << " " << newJ << " [" << newDir << "]" << endl;

    if (newDir == 0) newI--;
    else if (newDir == 1) newI++;
    else if (newDir == 2) newJ++;
    else if (newDir == 3) newJ--;

    if (newI >= 0 && newI < a.size() && newJ >= 0 && newJ < a[0].size()) {
      queue.push({{newI, newJ}, newDir});
    }
  }

  return mirrorsHit >= mirrorCount;
}

void solve() {
  ll r, c;
  cin >> r >> c;
  
  vector<vector<char>> a(r, vector<char>(c));

  ll mirrorCount = 0;
  REP (i, 0, r) {
    REP (j, 0, c) {
      cin >> a[i][j];
      if (a[i][j] != '.') mirrorCount++;
    }
  }

  string results = "";

  ll count = 0;
  REP (i, 0, c) {
    if (hitsAll(a, {0, i}, 1, mirrorCount)) results += "N" + to_string(i + 1) + " ", count++;
    if (hitsAll(a, {r - 1, i}, 0, mirrorCount)) results += "S" + to_string(i + 1) + " ", count++;
  }
  REP (j, 0, r) {
    if (hitsAll(a, {j, 0}, 2, mirrorCount)) results += "W" + to_string(j + 1) + " ", count++;
    if (hitsAll(a, {j, c - 1}, 3, mirrorCount)) results += "E" + to_string(j + 1) + " ", count++;
  }

  if (results.empty()) {
    cout << 0 << endl;
    return;
  }

  cout << count << endl;
  cout << results <<  endl;
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
