#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 9;
const int INF = 1e9;
int h[N];
int dp[N];
int n;
int f(int i)
{
    if (n == i)
        return 0;
    if (i > n)
        return INF;
    if (dp[i] != -1)
        return dp[i];
    int ans = abs(h[i] - h[i + 1]) + f(i + 1);
    ans = min(ans, abs(h[i] - h[i + 2]) + f(i + 2));
    dp[i] = ans;
    return dp[i];
}
int32_t main()
{
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }
    cout << f(1);
}