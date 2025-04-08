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

template<typename T>
T fastPow(T a, T b) {
  T res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}

template<typename T>
T modExp(T base, T exp, T mod) {
  T result = 1;
  base %= mod;

  while (exp > 0) {
    if (exp % 2 == 1) result = (result * base) % mod;

    base = (base * base) % mod;
    exp /= 2;
  }

  return result;
}

template<typename T>
T __lcm(T a, T b) {
  return (a * b) / __gcd(a, b);
}

template<typename T>
bool isPrime(T n) {
  if (n == 1) return false;
  T i = 2;
  while (i * i <= n) {
    if (n % i == 0) return false;
    i += 1;
  }
  return true;
}

template<typename T>
vector<T> factorize(T n) {
  vector<T> factors;
  for (T i = 2; i * i <= n; ++i) {
    while (n % i == 0) {
      factors.push_back(i);
      n /= i;
    }
  }
  if (n > 1) factors.push_back(n);
  return factors;
}

template<typename T>
T extendedGCD(T a, T b, T &x, T &y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }
  T x1, y1;
  T g = extendedGCD(b, a % b, x1, y1);
  x = y1;
  y = x1 - (a / b) * y1;
  return g;
}

template<typename T>
T modInv(T a, T m) {
  T x, y;
  T g = extendedGCD(a, m, x, y);
  if (g != 1) return -1;
  return (x % m + m) % m;
}

struct Congruence {
  ll a, m;
};

ll crt(const vector<Congruence> &congruences) {
  ll M = 1;
  for (auto const &congruence : congruences) {
    M *= congruence.m;
  }

  ll solution = 0;
  for (const Congruence &congruence : congruences) {
    ll a_i = congruence.a;
    ll M_i = M / congruence.m;
    ll N_i = modInv(M_i, congruence.m);
    solution = (solution + a_i * M_i % M * N_i) % M;
  }
  return solution;
}

struct TNode {
  map<char, TNode*> next;
  bool word = false;
};

struct Trie {
  TNode* root;

  Trie() {
    root = new TNode();
  }

  bool insert(const string &s) {
    TNode* node = root;
    bool isNew = false;
    for (char c : s) {
      if (!node->next.count(c)) {
        isNew = true;
        node->next[c] = new TNode();
      }
      node = node->next[c];
    }

    if (!node->word) {
      node->word = true;
      return true;
    }

    return false;
  }
};

const ll MAXN = 1e6 + 5;
vector<ll> fac(MAXN + 1);
vector<ll> inv(MAXN + 1);

void factorial() {
  fac[0] = 1;
  for (int i = 1; i <= MAXN; i++) fac[i] = fac[i - 1] * i % MOD;
}

void inverses() {
  inv[MAXN] = modExp(fac[MAXN], MOD - 2, MOD);
  for (int i = MAXN; i >= 1; i--) inv[i - 1] = inv[i] * i % MOD;
}

ll choose(int n, int r) {
  return fac[n] * inv[r] % MOD * inv[n - r] % MOD;
}

/*
template<typename T>
void make_set(vector<T> &dsu, T v) {
  dsu[v] = v;
}

template<typename T>
int find_set(vector<T> &dsu, T v) {
 if (v == dsu[v]) return v;
  return find_set(dsu, dsu[v]);
}

template<typename T>
void union_sets(vector<T> &dsu, T a, T b) {
  a = find_set(dsu, a);
  b = find_set(dsu, b);
  if (a != b) dsu[b] = a;
}
*/

template<typename T>
void make_set(vector<T> &dsu, vector<T> &size, T v) {
  dsu[v] = v;
  size[v] = 1;
}

template<typename T>
int find_set(vector<T> &dsu, T v) {
  if (v == dsu[v]) return v;
  return dsu[v] = find_set(dsu, dsu[v]);
}

template<typename T>
void union_sets(vector<T> &dsu, vector<T> &size, T a, T b) {
  a = find_set(dsu, a);
  b = find_set(dsu, b);
  if (a != b) {
    if (size[a] < size[b]) swap(a, b);
    dsu[b] = a;
    size[a] += size[b];
  }
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

#define TESTCASES 1

void solve() {
  ll n;
  cin >> n;

  cout << (n % 2 ? "YES" : "NO") << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  if (TESTCASES) cin >> t;
  while (t--) solve();
  return 0;
}
