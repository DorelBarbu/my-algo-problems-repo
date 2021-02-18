#include <bits/stdc++.h>
#define DEBUG(x) cout << "[" << #x << " : " << x << "] ";
#define DEBUG_NL(x) \
  DEBUG(x)          \
  cout << endl;
#define DEBUG_NL(x) \
  DEBUG(x)          \
  cout << endl;
#define DEBUG_V(v)                                 \
  cout << #v << "[]: ";                            \
  for (int i = 0; i < n; i++) cout << v[i] << ' '; \
  cout << endl;
#define between(a, x, b) a <= x && x <= b
using namespace std;

void read(int &n, int &k, vector<int> &h) {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    h.push_back(tmp);
  }
}

string solve(int n, int k, vector<int> &h) {
  int left = h[0], right = h[0];
  for (int i = 1; i < n; i++) {
    left = max(h[i], left + 1 - k);
    right = min(h[i] + k - 1, right + k - 1);
    if (left > right) {
      return "NO";
    }
  }
  // check the placement of the last piece
  if (between(left, h[n - 1], right)) return "YES";
  return "NO";
}

#define ONLINE_JUDGE
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int t;
  cin >> t;
  while (t) {
    t--;
    int n, k;
    vector<int> h;
    read(n, k, h);
    cout << solve(n, k, h) << endl;
  }
  return 0;
}