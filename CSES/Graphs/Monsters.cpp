// https://cses.fi/problemset/task/1194

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vint;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

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

vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<char> dirChars = {'D', 'U', 'R', 'L'};

void solve() {
  int n, m;
  cin >> n >> m;

  pair<int, int> A;
  vector<pair<int, int>> monsters;
  vector<vector<char>> a(n, vector<char>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];

      if (a[i][j] == 'A') A = {i, j}, a[i][j] = '.';
      else if (a[i][j] == 'M') monsters.push_back({i, j});
    }
  }

  vector<vector<int>> minSteps(n, vector<int>(m, INT_MAX));
  queue<tuple<int, int, int>> q;
  for (pair<int, int> monster : monsters) {
    q.push({monster.first, monster.second, 0});
  }
  while (!q.empty()) {
    int i = get<0>(q.front());
    int j = get<1>(q.front());
    int step = get<2>(q.front());
    q.pop();

    for (pair<int, int> d : dir) {
      int newI = i + d.first;
      int newJ = j + d.second;

      int newSteps = step + 1;
      if (newI >= 0 && newI < n && newJ >= 0 && newJ < m && a[newI][newJ] == '.' && minSteps[newI][newJ] > newSteps) {
        minSteps[newI][newJ] = newSteps;
        q.push({newI, newJ, newSteps});
      }
    }
  }
  
  q.push({A.first, A.second, 0});
  a[A.first][A.second] = '#';
  while (!q.empty()) {
    int i = get<0>(q.front());
    int j = get<1>(q.front());
    int step = get<2>(q.front());
    q.pop();

    for (int x = 0; x < dir.size(); x++) {
      int newI = i + dir[x].first;
      int newJ = j + dir[x].second;

      int newSteps = step + 1;

      if (newI >= 0 && newI < n && newJ >= 0 && newJ < m) {
        if (a[newI][newJ] == '.' && newSteps < minSteps[newI][newJ]) {
          a[newI][newJ] = x + '0';
          q.push({newI, newJ, newSteps});
        }
      } else {
        cout << "YES" << endl;

        string path;
        while (a[i][j] != '#') {
          int x = a[i][j] - '0';
          path += dirChars[x];
          i -= dir[x].first;
          j -= dir[x].second;
        }
        reverse(path.begin(), path.end());

        cout << path.size() << endl;
        cout << path << endl;
        return;
      }
    }
  }

  cout << "NO" << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  if (TESTCASES) cin >> t;
  while (t--) solve();
  return 0;
}
