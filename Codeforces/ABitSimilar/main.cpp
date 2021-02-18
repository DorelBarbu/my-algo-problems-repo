#include <bits/stdc++.h>
#define DEBUG(x) cout << "[" << #x << " : " << x << "] ";
#define DEBUG_NL(x) \
  DEBUG(x)          \
  cout << endl;
#define DEBUG_NL(x) \
  DEBUG(x)          \
  cout << endl;
#define DEBUG_V(v)      \
  cout << #v << "[]: "; \
  for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
#define ll long long

const int SEEN_SIZE = 2097152 + 10;

using namespace std;

int complement_2_decimal(string s) {
  int sz = s.size();
  int pwr = 0;
  int res = 0;
  for (int i = sz - 1; i >= 0; i--) {
    res += (s[i] == '0' ? 1 << pwr : 0);
    pwr++;
  }
  return res;
}

void decimal_2_binary(int x, vector<int>& res, int offset) {
  while (x) {
    res.push_back(x % 2);
    x /= 2;
  }
  while (res.size() < offset) {
    res.push_back(0);
  }
  reverse(res.begin(), res.end());
}

int findZeroCount(int k, int z) {
  int pwr = 0;
  while ((1 << pwr) <= z) {
    pwr++;
  }
  return k - pwr;
}

void print_solution(int zeros_count, int e, int k) {
  cout << "YES" << endl;
  for (int i = 0; i < zeros_count; i++) {
    cout << 0;
  }
  vector<int> v;
  decimal_2_binary(e, v, k - max(zeros_count, 0));
  for (int i = 0; i < v.size(); i++) {
    cout << v[i];
  }
  cout << endl;
}

void findFirstZero(string s, vector<int>& next0) {
  int n = s.size();
  if (s[n - 1] == '0') {
    next0[n - 1] = n - 1;
  }
  for (int i = n - 2; i >= 0; i--) {
    if (s[i] == '0') {
      next0[i] = i;
    } else {
      next0[i] = next0[i + 1];
    }
  }
}

bool solve(int n, int k, string s) {
  int z = n - k + 1;
  int zc = findZeroCount(k, z);
  vector<int> ans(max(zc, 0), 0);
  vector<bool> seen(SEEN_SIZE, false);
  vector<int> next_zero(n, -1);
  findFirstZero(s, next_zero);
  for (int i = 0; i < n - k + 1; i++) {
    string current_prefix;
    if (zc >= 0) {
      current_prefix = s.substr(i + zc, k - zc);
    } else {
      current_prefix = s.substr(i, k);
    }
    if (current_prefix.empty() == true) {
      continue;
    }
    if (next_zero[i] != -1 && next_zero[i] - i < zc) {
      continue;
    }
    int current_nr = complement_2_decimal(current_prefix);
    seen[current_nr] = true;
  }
  int e = -1;
  int limit = zc < 0 ? k : k - zc;
  for (int i = 0; i < (1 << limit); i++) {
    if (seen[i] == false) {
      e = i;
      break;
    }
  }
  if (e == -1) {
    cout << "NO" << endl;
  } else {
    print_solution(zc, e, k);
  }
  return true;
}

#define ONLINE_JUDGE
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int n, k;
    string s;
    cin >> n >> k >> s;
    solve(n, k, s);
  }
  return 0;
}