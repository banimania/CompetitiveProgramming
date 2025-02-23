#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vint;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define REPV(i, a, b) for (int i = a; i >= b; i--)
#define SCAN(v) for (int i = 0; i < v.size(); i++) cin >> v[i]
#define REPLIST(x, v) for (auto x : v)
#define PRINT(v) for (int i = 0; i < v.size(); i++) { cout << v[i] << (i == v.size() - 1 ? "" : " "); }
#define PRINTLN(v) for (int i = 0; i < v.size(); i++) { cout << v[i] << (i == v.size() - 1 ? "" : " "); } cout << endl
#define SORTINC(v) sort(v.begin(), v.end(), [](auto &x, auto &y) { return x < y; })
#define SORTDEC(v) sort(v.begin(), v.end(), [](auto &x, auto &y) { return x > y; })
#define MIN(v) min_element(v.begin(), v.end()) - v.begin()
#define MAX(v) max_element(v.begin(), v.end()) - v.begin()

const ll MOD = 1e9 + 7;

ll fastPow(ll a, ll b) {
  ll res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}

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

bool isPrime(ll n) {
  if (n == 1) return false;
  ll i = 2;
  while (i * i <= n) {
    if (n % i == 0) return false;
    i += 1;
  }
  return true;
}

void make_set(vector<int> &dsu, int v) {
  dsu[v] = v;
}

int find_set(vector<int> &dsu, int v) {
  if (v == dsu[v]) return v;
  return find_set(dsu, dsu[v]);
}

void union_sets(vector<int> &dsu, int a, int b) {
  a = find_set(dsu, a);
  b = find_set(dsu, b);
  if (a != b) dsu[b] = a;
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

void solve() {
  ll n, q;
  cin >> n >> q;

  vll prefixSum(n);
  cin >> prefixSum[0];
  REP (i, 1, n) {
    ll x;
    cin >> x;
    prefixSum[i] = prefixSum[i - 1] + x;
  }

  REP (i, 0, q) {
    ll a, b;
    cin >> a >> b;
    a--, b--;

    cout << prefixSum[b] - (a > 0 ? prefixSum[a - 1] : 0) << endl;
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
