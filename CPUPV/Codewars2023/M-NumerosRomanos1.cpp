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
#define MIN(v) min_element(a.begin(), a.end()) - a.begin()
#define MAX(v) max_element(a.begin(), a.end()) - a.begin()

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

struct MinOp {
  using T = ll;

  T operator()(T a, T b) const {
    return min(a, b);
  }

  T id() const {
    return LLONG_MAX;
  }
};

#define TESTCASES 1

void solve() {
  ll n;
  cin >> n;

  vector<string> final;
  int pos = 0;
  while (n) {
    ll dig = n % 10;
    n /= 10;
    string ans;

    if (dig == 1) {
      if (pos == 0) ans += "I";
      else if (pos == 1) ans += "X";
      else if (pos == 2) ans += "C";
      else if (pos == 3) ans += "M";
    } else if (dig == 2) {
      if (pos == 0) ans += "II";
      else if (pos == 1) ans += "XX";
      else if (pos == 2) ans += "CC";
      else if (pos == 3) ans += "MM";
    } else if (dig == 3) {
      if (pos == 0) ans += "III";
      else if (pos == 1) ans += "XXX";
      else if (pos == 2) ans += "CCC";
      else if (pos == 3) ans += "MMM";
    } else if (dig == 4) {
      if (pos == 0) ans += "IV";
      else if (pos == 1) ans += "XL";
      else if (pos == 2) ans += "CD";
    } else if (dig == 5) {
      if (pos == 0) ans += "V";
      else if (pos == 1) ans += "L";
      else if (pos == 2) ans += "D";
    } else if (dig == 6) {
      if (pos == 0) ans += "VI";
      else if (pos == 1) ans += "LX";
      else if (pos == 2) ans += "DC";
    } else if (dig == 7) {
      if (pos == 0) ans += "VII";
      else if (pos == 1) ans += "LXX";
      else if (pos == 2) ans += "DCC";
    } else if (dig == 8) {
      if (pos == 0) ans += "VIII";
      else if (pos == 1) ans += "LXXX";
      else if (pos == 2) ans += "DCCC";
    } else if (dig == 9) {
      if (pos == 0) ans += "IX";
      else if (pos == 1) ans += "XC";
      else if (pos == 2) ans += "CM";
    }

    final.push_back(ans);
    
    pos++;
  }

  reverse(final.begin(), final.end());
  REP (i, 0, final.size()) {
    cout << final[i];
  }
  cout << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  if (TESTCASES) cin >> t;
  while (t--) solve();
  return 0;
}
