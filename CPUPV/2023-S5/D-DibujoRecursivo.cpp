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
#define MIN(v) min_element(a.begin(), a.end()) - a.begin();
#define MAX(v) max_element(a.begin(), a.end()) - a.begin();

const ll MOD = 1e9 + 7;

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

struct MaxOp {
  using T = ll;

  T operator()(T a, T b) const {
    return max(a, b);
  }

  T id() const {
    return LLONG_MIN;
  }
};

#define TESTCASES 0

void dibujar(ll n, ll x, ll y, vector<vector<char>> &dibujo, char nextChar) {
  REP (i, x, x + n) {
    REP (j, y, y + n) {
      dibujo[i][j] = nextChar;
    }
  }

  if (n >= 5) {
    char newChar = (nextChar == '#' ? '.' : '#');
    if (n % 2) {
      ll newN = (n - 3) / 2;
      dibujar(newN, x + 1, y + 1, dibujo, newChar);
      dibujar(newN, x + 2 + newN, y + 1, dibujo, newChar);
      dibujar(newN, x + 1, y + 2 + newN, dibujo, newChar);
      dibujar(newN, x + 2 + newN, y + 2 + newN, dibujo, newChar);
    } else {
      ll newN = (n - 4) / 2;
      
      dibujar(newN, x + 1, y + 1, dibujo, newChar);
      dibujar(newN, x + 3 + newN, y + 1, dibujo, newChar);
      dibujar(newN, x + 1, y + 3 + newN, dibujo, newChar);
      dibujar(newN, x + 3 + newN, y + 3 + newN, dibujo, newChar);
    }
  }
}

void solve() {
  ll n;
  cin >> n;

  vector<vector<char>> dibujo(n, vector<char>(n));
  dibujar(n, 0, 0, dibujo, '#');

  REP (i, 0, n) {
    REP (j, 0, n) {
      cout << dibujo[i][j];
    }
    cout << endl;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  if (TESTCASES) cin >> t;
  while (t--) solve();
  return 0;
}
