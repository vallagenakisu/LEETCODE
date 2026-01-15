#include <bits/stdc++.h>
using namespace std;
const int N = 55;
const int K = 1009;
int A[N];
int C[N];
int n, k , mod = 100000007;
int dp[N][K];
int f(int i, int value)
{

    if (i == n + 1)
    {
        if (value == k)
            return 1;
        return 0;
    }
    if (value == k)
        return 1;
    if (value > k)
        return 0;
    if (dp[i][value] != -1)
        return dp[i][value];
    int ans = 0;
    for (int k = 0; k <= C[i]; k++)
    {
        ans += f(i + 1, value + A[i] * k);
    }
    ans %= mod;
    dp[i][value] = ans;
    return dp[i][value];
}
void sol()
{
    memset(dp, -1, sizeof(dp));
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> C[i];
    }
    cout<< f(1, 0);
}
int main()
{
    int case_num;
    int t;
    cin >> t;
    case_num = t;
    while (t--)
    {
        cout << "Case " << case_num - t << ": ";
        sol();
        cout << endl;
    }
}