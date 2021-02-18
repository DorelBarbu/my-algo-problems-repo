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
#define ll long long

using namespace std;

// #define ONLINE_JUDGE
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> g(n + 1, 0);
    vector<bool> seen(n + 1, false);
    //read
    int number_of_cycles = 0, number_of_loops = 0;
    for(int i = 0; i < m; i++) {
      int x, y;
      cin >> x >> y;
      if(x == y) {
        number_of_loops ++;
        continue;
      }
      g[x] = y;
    }
    //solve
    for(int i = 1; i <= n; i++) {
      int it = i;
      if(seen[it] || g[it] == 0) continue;
      // DEBUG("start") DEBUG(it) DEBUG_NL(g[it])
      while(seen[it] == false && g[it] != 0) {
        // DEBUG_NL(it)
        seen[it] = true;
        it = g[it];
      }
      seen[it] = true;
      // DEBUG(i) DEBUG(it) DEBUG_NL(g[it])
      number_of_cycles += (it == i);
    }
    //answer
    // DEBUG(m) DEBUG(number_of_cycles) DEBUG_NL(number_of_loops)
    cout << m + number_of_cycles - number_of_loops << endl;
    
  }
  return 0;
}