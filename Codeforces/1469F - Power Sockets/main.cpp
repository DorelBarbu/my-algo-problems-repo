#include <bits/stdc++.h>
#define DEBUG(x) cout << "[" << #x << " : " << x << "] ";
#define DEBUG_NL(x) \
  DEBUG(x)          \
  cout << endl;
#define DEBUG_NL(x) \
  DEBUG(x)          \
  cout << endl;
#define DEBUG_V(v)                                              \
  cout << #v << "[]: ";                                         \
  for (long long i = 0; i < v.size(); i++) cout << v[i] << ' '; \
  cout << endl;
#define ll long long

using namespace std;

class SegmentTree {
 private:
  long long left(long long k) { return 2 * k + 1; }
  long long right(long long k) { return 2 * k + 2; }

 public:
  vector<long long> t;
  long long n;

  SegmentTree(long long n) {
    t.resize(4 * n + 1);
    this->n = n;
    fill(t.begin(), t.end(), 0);
  }

  void update(long long k, long long left, long long right, long long a,
              long long b, long long x) {
    assert(k < t.size());
    if (left > right) return;
    if (a <= left && right <= b) {
      t[k] += x;
      return;
    }
    long long m = (left + right) / 2;
    if (a <= m) {
      update(this->left(k), left, m, a, b, x);
    }
    if (m < b) {
      update(this->right(k), m + 1, right, a, b, x);
    }
  }

  long long get(long long k, long long left, long long right, long long pos) {
    if (left == right) {
      return t[k];
    }
    long long m = (left + right) / 2;
    if (pos <= m) {
      return t[k] + get(this->left(k), left, m, pos);
    } else {
      return t[k] + get(this->right(k), m + 1, right, pos);
    }
  }

  long long query(long long pos) { return this->get(0, 0, this->n - 1, pos); }

  void set(long long a, long long b, long long x) {
    // DEBUG(a) DEBUG(b) DEBUG(x) cout << endl;
    this->update(0, 0, this->n - 1, a, b, x);
  }
};

void test_tree() {
  SegmentTree tree(8);
  tree.set(0, 0, 1);
  // first chain
  tree.set(2, 3, 1);
  tree.set(2, 2, 1);
  tree.set(0, 0, -1);
  DEBUG(tree.query(0));
  assert(tree.query(0) == 0);
  assert(tree.query(1) == 0);
  assert(tree.query(2) == 2);
  assert(tree.query(3) == 1);
  // second chain
  tree.set(4, 5, 1);
  tree.set(4, 4, 1);
  tree.set(2, 2, -1);
  assert(tree.query(0) == 0);
  assert(tree.query(1) == 0);
  assert(tree.query(2) == 1);
  assert(tree.query(3) == 1);
  assert(tree.query(4) == 2);
  assert(tree.query(5) == 1);
  // third chain
  tree.set(4, 4, 1);
  tree.set(4, 4, 1);
  tree.set(2, 2, -1);
  assert(tree.query(0) == 0);
  assert(tree.query(1) == 0);
  assert(tree.query(2) == 0);
  assert(tree.query(3) == 1);
  assert(tree.query(4) == 4);
  assert(tree.query(5) == 1);
}

bool cmp(long long a, long long b) { return a - b > 0; }

long long solve(long long n, long long k, vector<long long> &L) {
  sort(L.begin(), L.end(), cmp);
  SegmentTree tree(n + 500);
  tree.set(0, 0, 1);
  long long closest_root_height = 0;
  long long seen_white_beads = 1;
  long long answer = 10000000;
  for (long long i = 0; i < n; i++) {
    long long nodes_left = L[i] / 2;
    long long nodes_right = L[i] - nodes_left - 1;

    tree.set(closest_root_height + 2, closest_root_height + nodes_left + 1, 1);
    tree.set(closest_root_height + 2, closest_root_height + nodes_right + 1, 1);
    tree.set(closest_root_height, closest_root_height, -1);

    seen_white_beads += nodes_left + nodes_right - 1;

    if (seen_white_beads >= k) {
      int height_left = closest_root_height + 1 + nodes_left;
      int height_right = closest_root_height + 1 + nodes_right;
      // try and pick the left branch
      if(seen_white_beads - nodes_right >= k) {
        answer = min(answer, height_left -  (seen_white_beads - k));
      }
      if(seen_white_beads - nodes_left >= k) {
        answer = min(answer, height_left - (seen_white_beads - k));
      }
      if(seen_white_beads - nodes_left < k && seen_white_beads - nodes_right < k) {
        answer = min(answer, height_right - (seen_white_beads - k));
      }
      int diff = seen_white_beads - k;
      // answer = min(answer, )
    }

    DEBUG_NL(seen_white_beads)
  }

  if (seen_white_beads < k) {
    answer = -1;
  }

  // DEBUG_NL(answer);
  return answer;
}

// #define ONLINE_JUDGE
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  // test_tree();
  long long n, k;
  cin >> n >> k;
  vector<long long> L(n);
  for (long long i = 0; i < n; i++) {
    cin >> L[i];
  }
  cout << solve(n, k, L);
  // test_tree();
  return 0;
}