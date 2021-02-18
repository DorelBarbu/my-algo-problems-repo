#include <bits/stdc++.h>
#define DEBUG(x) cout << "[" << #x << " : " << x << "] ";
#define DEBUG_NL(x) \
  DEBUG(x)          \
  cout << endl;
#define DEBUG_V(v)                                 \
  cout << #v << "[]: ";                            \
  for (int i = 0; i < n; i++) cout << v[i] << ' '; \
  cout << endl;
#define ll long long

using namespace std;

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
    int n, m;
    cin >> n >> m;
    vector<vector<int> > a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> a[i][j];
        a[i][j]--;
      }
    }
    vector<int> dist(3, 0);
    vector<int> dir{0, 1, 2};
    char op;
    while (m) {
      cin >> op;
      switch (op) {
        case 'R':
          dist[1] = (dist[1] + 1) % n;
          break;
        case 'L':
          dist[1] = (dist[1] + n - 1) % n;
          break;
        case 'D':
          dist[0] = (dist[0] + 1) % n;
          break;
        case 'U':
          dist[0] = (dist[0] + n - 1) % n;
          break;
        case 'I':
          swap(dist[1], dist[2]);
          swap(dir[1], dir[2]);
          break;
        case 'C':
          swap(dist[0], dist[2]);
          swap(dir[0], dir[2]);
          break;
      }
      m--;
    }
    vector<vector<int> > res(n, vector<int>(n));
    vector<int> v(3);
    // DEBUG_V(dir)
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        vector<int> d = {i, j, a[i][j]};
        for (int k = 0; k < 3; k++) {
          v[k] = (dist[k] + d[dir[k]]) % n;
        }
        res[v[0]][v[1]] = v[2];
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << res[i][j] + 1 << ' ';
      }
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}