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

struct Participante {
  string arma;
  int capa;
};

struct PPTOp {
  using T = Participante;

  T operator()(T a, T b) const {
    if (a.capa % 2 == 0) {
      if ((a.arma == "tijera" && b.arma == "piedra") || (a.arma == "piedra" && b.arma == "tijera")) return {"piedra", a.capa + 1};
      else if ((a.arma == "tijera" && b.arma == "papel") || (a.arma == "papel" && b.arma == "tijera")) return {"tijera", a.capa + 1};
      else if ((a.arma == "piedra" && b.arma == "papel") || (a.arma == "papel" && b.arma == "piedra")) return {"papel", a.capa + 1};
      return { a.arma, a.capa + 1 };
    }

    if ((a.arma == "tijera" && b.arma == "piedra") || (a.arma == "piedra" && b.arma == "tijera")) return {"tijera", a.capa + 1};
    else if ((a.arma == "tijera" && b.arma == "papel") || (a.arma == "papel" && b.arma == "tijera")) return {"papel", a.capa + 1};
    else if ((a.arma == "piedra" && b.arma == "papel") || (a.arma == "papel" && b.arma == "piedra")) return {"piedra", a.capa + 1};
    return { a.arma, a.capa + 1 };
  }
  
  T id() const {
    cout << "AAAAAA" << endl;
    return {"", 0};
  }
};

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

#define TESTCASES 0

void solve() {
  ll n, m;
  cin >> n >> m;

  vector<Participante> a(pow(2, n));
  REP (i, 0, a.size()) {
    string arma;
    cin >> arma;
    a[i] = {arma, 0};
  }
  SegTree<Participante, PPTOp> segTree(a);

  REP (i, 0, m) {
    ll cambioId;
    cin >> cambioId;
    string nuevo;
    cin >> nuevo;
    segTree.update(cambioId - 1, {nuevo, 0});
    cout << segTree.query(0, a.size() - 1).arma << endl;
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
