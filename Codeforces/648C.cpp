#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vint;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define REPV(i, a, b) for (int i = a; i >= b; i--)
#define SCAN(v) for (int i = 0; i < v.size(); i++) cin >> v[i]
#define REPLIST(x, v) for (auto x : v)
#define PRINT(v) for (auto x : v) { cout << x << " "; } cout << endl;
#define SORTINC(v) sort(v.begin(), v.end(), [](auto &x, auto &y) { return x < y; });
#define SORTDEC(v) sort(v.begin(), v.end(), [](auto &x, auto &y) { return x > y; });
#define MIN(v) min_element(v.begin(), v.end()) - v.begin()
#define MAX(v) max_element(v.begin(), v.end()) - v.begin()

const ll MOD = 1e9 + 7;

ll modExp(ll base, ll exp, ll mod) {
  ll result = 1;
  base %= mod;

  while (exp > 0) {
    if (exp % 2 == 1) result = (result * base) % mod;

    base = (base * base) % mod;
    exp /= 2;
  }

  return result;
}

void make_set(vector<int> &nodoPadre, int v) {
  nodoPadre[v] = v;
}

int find_set(vector<int> &nodoPadre, int v) {
  if (v == nodoPadre[v]) return v;
  return find_set(nodoPadre, nodoPadre[v]);
}

void union_sets(vector<int> &nodoPadre, int a, int b) {
  a = find_set(nodoPadre, a);
  b = find_set(nodoPadre, b);
  if (a != b) nodoPadre[b] = a;
}

template <typename T, typename Op>
class SegTree {
public:
  vector<T> tree;
  int n;
  Op op;

  SegTree(const vector<T> & v) {
    n = v.size();
    tree.resize(4 * n);

    build(v, 0, 0, v.size() - 1);
  }

  void build(const vector<T>& arr, int node, int start, int end) {
    if (start == end) {
      tree[node] = arr[start];
    } else {
      int mid = (start + end) / 2;
      int leftChild = 2 * node + 1;
      int rightChild = 2 * node + 2;
      
      build(arr, leftChild, start, mid);
      build(arr, rightChild, mid + 1, end);

      tree[node] = op(tree[leftChild], tree[rightChild]);
    }
  }

  T query(int l, int r) {
    return query(0, 0, n - 1, l, r);
  }

  T query(int node, int start, int end, int L, int R) {
    if (R < start || end < L) {
      return op.id();
    }
    if (L <= start && end <= R) {
      return tree[node];
    }

    int mid = (start + end) / 2;
    int leftChild = 2 * node + 1;
    int rightChild = 2 * node + 2;

    T leftResult = query(leftChild, start, mid, L, R);
    T rightResult = query(rightChild, mid + 1, end, L, R);

    return op(leftResult, rightResult);
  }

  void update(int idx, T val) {
    update(0, 0, n - 1, idx, val);
  }

  void update(int node, int start, int end, int idx, T val) {
    if (start == end) {
      tree[node] = val;
    } else {
      int mid = (start + end) / 2;
      int leftChild = 2 * node + 1;
      int rightChild = 2 * node + 2;

      if (start <= idx && idx <= mid) {
        update(leftChild, start, mid, idx, val);
      } else {
        update(rightChild, mid + 1, end, idx, val);
      }

      tree[node] = op(tree[leftChild], tree[rightChild]);
    }
  }
};

struct SumOp {
  using T = ll;

  T operator()(T a, T b) const {
    return a + b;
  }

  T id() const {
    return 0;
  }
};

struct MinOp {
  using T = ll;

  T operator()(T a, T b) const {
    return min(a, b);
  }

  T id() const {
    return LLONG_MAX;
  }
};

#define TESTCASES 0

vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
string dirChars = "LRUD";

void solve() {
  int n, m;
  cin >> n >> m;
  pair<int, int> inicio;
  vector<vector<char>> mapa(n, vector<char>(m));
  vector<vector<int>> prev(n, vector<int>(m, -1));
  REP (i, 0, n) {
    REP (j, 0, m) {
      cin >> mapa[i][j];

      if (mapa[i][j] == 'S') {
        inicio = {i, j};
        mapa[i][j] = '*';
      }
    }
  }
  prev[inicio.first][inicio.second] = -2;

  stack<tuple<int, int, int>> st;
  st.push({inicio.first, inicio.second, 0});
  while (!st.empty()) {
    auto [i, j, steps] = st.top();
    st.pop();

    if (steps != 0 && pair<int, int>{i, j} == inicio) {
      // cout << "llegado en " << steps << endl;
      break;
    }

    for (int dir = 0; dir < dirs.size(); dir++) {
      auto [di, dj] = dirs[dir];
      int newI = i + di;
      int newJ = j + dj;

      if (newI >= 0 && newI < n && newJ >= 0 && newJ < m && mapa[newI][newJ] == '*') {
        if (prev[newI][newJ] == -2 && steps != 1) {
          st.push({newI, newJ, steps + 1});
          prev[newI][newJ] = dir;
          break;
        }

        if (prev[newI][newJ] == -1) {
          st.push({newI, newJ, steps + 1});
          prev[newI][newJ] = dir;

          if (steps == 0) break;
        }
      }
    }
  }

  // REP (i, 0, n) {
  //   REP (j, 0, m) {
  //     if (prev[i][j] == -1) cout << "X" << " ";
  //     else cout << dirChars[prev[i][j]] << " ";
  //   }
  //   cout << endl;
  // }
  // cout << endl;

  pair<int, int> current = inicio;
  string solution;
  do {
    int di = -dirs[prev[current.first][current.second]].first;
    int dj = -dirs[prev[current.first][current.second]].second;
    solution.push_back(dirChars[prev[current.first][current.second]]);
    current.first += di;
    current.second += dj; 
  } while (current != inicio);

  cout << solution << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  if (TESTCASES) cin >> t;
  while (t--) solve();
  return 0;
}
