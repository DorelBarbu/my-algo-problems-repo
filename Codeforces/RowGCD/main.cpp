#include <bits/stdc++.h>
#define DEBUG(x) cout << "[" << #x << " : " << x << "] ";
#define DEBUG_NL(x) \
    DEBUG(x)        \
    cout << endl;
#define ll long long

using namespace std;

// #define ONLINE_JUDGE

long long gcd(long long x, long long y)
{
    if (x == 0 || y == 0)
    {
        return x == 0 ? y : x;
    }
    long long r;
    while (y != 0)
    {
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<long long> b(m);
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    long long commonGCD = 0;
    for (int i = 1; i < n; i++)
    {
        commonGCD = gcd(commonGCD, abs(a[i] - a[0]));
    }
    for (int j = 0; j < m; j++)
    {
        cout << gcd(b[j] + a[0], commonGCD) << ' ';
    }
    return 0;
}