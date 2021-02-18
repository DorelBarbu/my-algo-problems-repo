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
#define DEBUG_V_RANGE(v, a, b)                      \
  cout << #v << "[]: ";                             \
  for (int i = a; i <= b; i++) cout << v[i] << ' '; \
  cout << endl;
#define ll long long
using namespace std;

void print(vector<pair<int, int>> &v) {
  cout << v.size() << endl;
  for (pair<int, int> p : v) {
    cout << p.first << ' ' << p.second << endl;
  }
}

void solve(int n) {
  int x = n;
  vector<pair<int, int>> ans;
  while (x > 2) {
    int y = 1;
    while (y < x / y + 1) {
      y++;
    }
    for (int i = y + 1; i < x; i++) {
      ans.push_back(make_pair(i, x));
    }
    ans.push_back(make_pair(x, y));
    ans.push_back(make_pair(x, y));
    x = y;
  }
  print(ans);
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
    int n;
    cin >> n;
    solve(n);
  }
  return 0;
}