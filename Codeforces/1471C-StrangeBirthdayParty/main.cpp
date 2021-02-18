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

void read(int &n, int &m, vector<ll> &k, vector<ll> &c) {
  for (int i = 0; i < n; i++) {
    cin >> k[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> c[i];
  }
}

void print_v(vector<pair<int, int>> &v) {
  cout << "costs: ";
  for (int i = 0; i < v.size(); i++) {
    cout << "(" << v[i].first << ", " << v[i].second << ")" << ' ';
  }
  cout << endl;
}

bool cmp(pair<int, int> &p1, pair<int, int> &p2) {
  return p2.second < p1.second;
}

ll solve(int n, int m, vector<ll> &k, vector<ll> &c) {
  // DEBUG_NL("solve") DEBUG_V(k) DEBUG_V(c) 
  vector<pair<int, int>> costs;
  for (int i = 0; i < n; i++) {
    costs.push_back(make_pair(i, c[k[i] - 1]));
  }
  sort(costs.begin(), costs.end(), cmp);
  // print_v(costs);
  ll answer = 0;
  int j = 0;
  for(int i = 0; i < n; i++) {
    if(j < m && costs[i].second > c[j]) {
      answer += c[j];
      j++;
    } else {
      answer += costs[i].second;
    }
  }
  // DEBUG_NL(answer)
  return answer;
}

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
    vector<ll> k(n);
    vector<ll> c(m);
    read(n, m, k, c);
    cout << solve(n, m, k, c) << endl;
  }
  return 0;
}