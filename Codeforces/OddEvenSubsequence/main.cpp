#include <iostream>
#include <fstream>

const int MAXN = 2 * 1e5;
const int INF = 1 * 1e9;

int n, k, a[MAXN + 1];

using namespace std;

ifstream in("date.in");

bool check(int x, int n, int a[], int rem)
{
  int len = 0;
  for (int i = 0; i < n; i++)
  {
    if (len % 2 != rem)
    {
      if (a[i] <= x)
      {
        len++;
      }
    }
    else
    {
      len++;
    }
  }

  return len >= k;
}

int solve()
{
  int left = 1, right = INF, ans = INF;
  while (left <= right)
  {
    int m = (left + right) / 2;
    if (check(m, n, a, 1) || check(m, n, a, 0))
    {
      ans = m;
      right = m - 1;
    }
    else
    {
      left = m + 1;
    }
  }
  return ans;
}

void read()
{
  in >> n >> k;
  for (int i = 0; i < n; i++)
  {
    in >> a[i];
  }
}

int main()
{
  read();
  int x = solve(), answer = INF;
  for (int i = 0; i < n; i++)
  {
    if (a[i] >= x)
    {
      answer = min(answer, a[i]);
    }
  }
  cout<<answer;
  return 0;
} 