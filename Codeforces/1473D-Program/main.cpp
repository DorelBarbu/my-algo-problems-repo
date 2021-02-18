#include <bits/stdc++.h>
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

int min(int x, int y) { return x > y ? y : x; }

int max(int x, int y) { return x > y ? x : y; }

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
      DEBUG_NL(v)
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
    return this->query(0, 0, this->n - 1, left, right, min, 100000, this->treeMin);
  }

  int getMax(int left, int right) {
    return this->query(0, 0, this->n - 1, left, right, max, -100000, this->treeMax);
  }
};

void test_segment_tree() {
  int n = 4;
  SegmentTree t(n);
  t.set(3, 2);
  t.set(0, 1);
  t.set(1, 4);
  t.set(2, 3);
  DEBUG_V(t.treeMin)
  assert(t.getMin(2, 3) == 2);
  assert(t.getMin(1, 2) == 3);
  assert(t.getMin(2, 3) == 2);
  assert(t.getMin(1, 1) == 4);
  assert(t.getMax(0, 1) == 4);
  assert(t.getMax(2, 3) == 3);
  assert(t.getMax(1, 3) == 4);
}

// #define ONLINE_JUDGE
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    string s;
    cin >> n >> m >> s;
    while (m--) {
      int l, r;
      cin >> l >> r;
    }
  }
  test_segment_tree();
#endif
  return 0;
}