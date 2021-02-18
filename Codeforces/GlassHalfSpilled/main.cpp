#include <bits/stdc++.h>
#define DEBUG(x) cerr << "[" << #x << " : " << x << "] ";
#define DEBUG_NL(x) \
  DEBUG(x)          \
  cerr << endl;
#define ll long long
using namespace std;

const int MAX_N = 100;
const int MAX_AB = 100;
const int MAX_SUM = MAX_N * MAX_AB;

int dp[2][MAX_N + 1][MAX_SUM + 1];
#define ONLINE_JUDGE

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  vector<int> a(n + 1), b(n + 1);
  int B = 0;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i] >> b[i];
    B += b[i];
  }
  //Base cases
  for (int i = 0; i <= 1; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      for (int A = 0; A <= MAX_SUM; A++)
      {
        dp[i][j][A] = -MAX_SUM;
      }
    }
  }
  dp[0][0][0] = 0;
  //Solve with dp
  vector<double> ans(n + 1, 0);
  for (int i = 1; i <= n; i++)
  {
    int curr = i % 2;
    int prev = !curr;
    for (int k = 0; k <= n; k++)
    {
      for (int A = 0; A <= MAX_SUM; A++)
      {
        if (A - a[i] >= 0 && k - 1 >= 0)
        {
          dp[curr][k][A] = max(
              dp[curr][k][A],
              max(dp[prev][k][A], dp[prev][k - 1][A - a[i]] + b[i]));
        }
        dp[curr][k][A] = max(dp[prev][k][A], dp[curr][k][A]);
        ans[k] = max(ans[k], min(A * 1.0, (B + dp[curr][k][A]) / 2.0));
      }
    }
  }
  for (int i = 1; i <= n; i++)
  {
    cout << fixed << setprecision(10) << ans[i] << ' ';
  }
  return 0;
}