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

struct State {
  ll node, weight;
  State(ll node, ll weight) : node(node), weight(weight) {};
};

void solve() {
  ll n, m;
  cin >> n >> m;

  vector<vll> ady(n, vll());
  map<pair<ll, ll>, ll> edges;
  REP (i, 0, m) {
    ll ex1, ex2, w;
    cin >> ex1 >> ex2 >> w;
    ex1--, ex2--;
    ady[ex1].push_back(ex2);
    ady[ex2].push_back(ex1);
    edges[{ex1, ex2}] = w;
    edges[{ex2, ex1}] = w;
  }

  priority_queue<State, vector<State>, function<bool(State, State)>> pq([](const State &x, const State &y) {
    return x.weight > y.weight;
  });
  vector<ll> dist(n, LLONG_MAX);
  dist[0] = 0;
  pq.push({0, 0});

  vll previous(n, -1);

  while (!pq.empty()) {
    State current = pq.top();
    pq.pop();

    ll node = current.node;
    ll weight = current.weight;

    if (node == n - 1) {
      break;
    }

    REP (i, 0, ady[node].size()) {
      ll vecino = ady[node][i];
      ll edgeWeight = edges[{node, vecino}];
      if (vecino != node && edgeWeight != -1 && dist[vecino] > weight + edgeWeight) {
        pq.push({vecino, weight + edgeWeight});
        dist[vecino] = weight + edgeWeight;
        previous[vecino] = node;
      }
    }
  }

  if (dist[n - 1] == LLONG_MAX) {
    cout << -1 << endl;
    return;
  }

  vll solution;
  ll actual = n - 1;
  while (actual != -1) {
    solution.push_back(actual + 1);
    actual = previous[actual];
  }
  reverse(solution.begin(), solution.end());
  PRINTLN(solution);
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
