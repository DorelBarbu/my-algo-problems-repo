#include <assert.h>

#include <iostream>
#include <vector>
#define DEBUG(x) cout << "[" << #x << " : " << x << "] ";
#define DEBUG_NL(x) \
  DEBUG(x)          \
  cout << endl;
#define DEBUG_NL(x) \
  DEBUG(x)          \
  cout << endl;
#define DEBUG_V(v)                                        \
  cout << #v << "[]: ";                                   \
  for (int i = 0; i < v.size(); i++) cout << v[i] << ' '; \
  cout << endl;
#define ll long long

using namespace std;

const int INF = 3 * 1e5;

int min(int x, int y) { return x > y ? y : x; }

int max(int x, int y) { return x > y ? x : y; }

class TreeNode {
 public:
  int position;
  int mn;
  int mx;
  TreeNode(int position, int mn, int mx) {
    this->position = position;
    this->mn = mn;
    this->mx = mx;
  }
};

class SegmentTree {
 private:
  int left(int v) { return 2 * v + 1; }

  int right(int v) { return 2 * v + 2; }

  void update(int v, int tl, int tr, int position, int value) {
    // DEBUG(v) DEBUG(tl) DEBUG_NL(tr)
    if (tl > tr) {
      return;
    }
    if (tl == tr) {
      this->treeMin[v] = value;
      this->treeMax[v] = value;
      return;
    }
    assert(v < this->treeMin.size());
    int m = (tl + tr) / 2;
    if (position <= m) {
      update(left(v), tl, m, position, value);
    } else {
      update(right(v), m + 1, tr, position, value);
    }
    this->treeMin[v] = min(this->treeMin[left(v)], this->treeMin[right(v)]);
    this->treeMax[v] = max(this->treeMax[left(v)], this->treeMax[right(v)]);
  }

  int query(int v, int tl, int tr, int left, int right, int (*f)(int x, int y),
            int INF, vector<int> &t) {
    if (right < tl || tr < left) {
      return INF;
    }
    if (left <= tl && tr <= right) {
      return t[v];
    }
    int m = (tl + tr) / 2;
    int min_left = query(this->left(v), tl, m, left, right, f, INF, t);
    int min_right = query(this->right(v), m + 1, tr, left, right, f, INF, t);
    return f(min_left, min_right);
  }

 public:
  vector<int> treeMin;
  vector<int> treeMax;
  int n;

  SegmentTree(int tree_size) {
    this->treeMin.resize(4 * tree_size + 10);
    this->treeMax.resize(4 * tree_size + 10);
    this->n = tree_size;
  }

  void set(int position, int value) {
    this->update(0, 0, this->n - 1, position, value);
  }

  int getMin(int left, int right) {
    return this->query(0, 0, this->n - 1, left, right, min, INF, this->treeMin);
  }

  int getMax(int left, int right) {
    return this->query(0, 0, this->n - 1, left, right, max, -INF,
                       this->treeMax);
  }
};

void test_segment_tree() {
  int n = 4;
  SegmentTree t(n);
  t.set(3, 2);
  t.set(0, 1);
  t.set(1, 4);
  t.set(2, 3);
  assert(t.getMin(2, 3) == 2);
  assert(t.getMin(1, 2) == 3);
  assert(t.getMin(2, 3) == 2);
  assert(t.getMin(1, 1) == 4);
  assert(t.getMax(0, 1) == 4);
  assert(t.getMax(2, 3) == 3);
  assert(t.getMax(1, 3) == 4);
}

int sum(int left, int right, vector<int> v) {
  assert(left > 0);
  return v[right] - v[left - 1];
}

int query(int left, int right, SegmentTree &tree, vector<int> partial_sum,
          int n) {
  int a1 = tree.getMin(0, left - 1);
  int b1 = tree.getMax(0, left - 1);
  int d = sum(left, right, partial_sum);
  int a2 = tree.getMin(right + 1, n) - d;
  int b2 = tree.getMax(right + 1, n) - d;

  int result = max(b1, b2) - min(a1, a2) + 1;
  // DEBUG_NL(result)
  // DEBUG_NL("----")
  return result;
}

void solve(int n, int m, string s) {
  SegmentTree tree(n + 1);

  vector<int> v(n + 1);
  vector<int> partial_sum(n + 1);
  v[0] = 0;
  partial_sum[0] = 0;
  tree.set(0, 0);
  for (int i = 0; i < n; i++) {
    if (s[i] == '-') {
      v[i + 1] = v[i] - 1;
    } else {
      v[i + 1] = v[i] + 1;
    }
    tree.set(i + 1, v[i + 1]);
  }
  while (m--) {
    int l, r;
    cin >> l >> r;
    cout << query(l, r, tree, v, n) << endl;
  }
}

void generate_test() {
  cout << 200000 << ' ' << 200000 << endl;
  for (int i = 0; i < 200000; i++) {
    cout << "+";
  }
  cout << endl;
  for (int i = 1; i <= 200000; i++) {
    cout << 1 << ' ' << i << endl;
  }
}

// #define ONLINE_JUDGE
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    string s;
    cin >> n >> m >> s;
    solve(n, m, s);
  }
  // test_segment_tree();
  // generate_test();
  return 0;
}