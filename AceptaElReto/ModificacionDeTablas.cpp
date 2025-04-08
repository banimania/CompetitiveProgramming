#include <bits/stdc++.h>
using namespace std;

template <typename T, typename Op>
class SegTree {
public:
  int n;
  vector<T> tree, lazy;
  Op op;

  SegTree(const vector<T>& v) {
    n = v.size();
    tree.resize(4 * n);
    lazy.assign(4 * n, op.id_lazy());
    build(v, 0, 0, n - 1);
  }

  void build(const vector<T>& v, int node, int l, int r) {
    if (l == r) {
      tree[node] = v[l];
    } else {
      int mid = (l + r) / 2;
      build(v, 2 * node + 1, l, mid);
      build(v, 2 * node + 2, mid + 1, r);
      tree[node] = op(tree[2 * node + 1], tree[2 * node + 2]);
    }
  }

  void push(int node, int l, int r) {
    if (lazy[node] != op.id_lazy()) {
      tree[node] += (r - l + 1) * lazy[node];
      if (l != r) {
        lazy[2 * node + 1] += lazy[node];
        lazy[2 * node + 2] += lazy[node];
      }
      lazy[node] = op.id_lazy();
    }
  }

  T query(int ql, int qr) {
    return query(0, 0, n - 1, ql, qr);
  }

  T query(int node, int l, int r, int ql, int qr) {
    push(node, l, r);
    if (qr < l || r < ql) return op.id();
    if (ql <= l && r <= qr) return tree[node];

    int mid = (l + r) / 2;
    T left = query(2 * node + 1, l, mid, ql, qr);
    T right = query(2 * node + 2, mid + 1, r, ql, qr);
    return op(left, right);
  }

  void update(int ql, int qr, T val) {
    update(0, 0, n - 1, ql, qr, val);
  }

  void update(int node, int l, int r, int ql, int qr, T val) {
    push(node, l, r);
    if (qr < l || r < ql) return;
    if (ql <= l && r <= qr) {
      lazy[node] += val;
      push(node, l, r);
      return;
    }

    int mid = (l + r) / 2;
    update(2 * node + 1, l, mid, ql, qr, val);
    update(2 * node + 2, mid + 1, r, ql, qr, val);
    tree[node] = op(tree[2 * node + 1], tree[2 * node + 2]);
  }
};

struct SumOp {
  using T = int;

  T operator()(T a, T b) const {
    return a + b;
  }

  T id() const {
    return 0;
  }

  T id_lazy() const {
    return 0;
  }
};

int main() {
  int f, c, n;
  while (cin >> f >> c >> n) {
    if (!f && !c && !n) break;

    vector<int> v(f * c);
    SegTree<int, SumOp> segTree(v);

    for (int x = 0; x < n; x++) {
      int i, a, b, m;
      cin >> i >> a >> b >> m;

      int l = i * c + a;
      int r = i * c + b;

      segTree.update(l, r, m);
    }

    for (int i = 0; i < f; i++) {
      for (int j = 0; j < c; j++) {
        int id = j * c + i;
        cout << segTree.query(id, id) << (j == c - 1 ? "" : " ");
      }
      cout << endl;
    }
  }

  return 0;
}
