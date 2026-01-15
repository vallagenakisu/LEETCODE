#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n, w;
const int N = 105;
const int W = 1e5 + 9;
int weights[N], values[W];
int dp[N][W];
// 3 8
// 3 30
// 4 50
// 5 60
int knapsack(int i, int weight)
{
    if(i == n + 1 ) return 0;
    if(dp[i][weight] != -1) return dp[i][weight];
    int ans = 0 ;
    // select
    if (weight + weights[i] <= w)
    {
        ans = values[i] + knapsack(i + 1, weight + weights[i]);
    }
    // not selected
    ans = max( ans, knapsack(i+1 , weight ));
    dp[i][weight] = ans;
    return ans;
}
int32_t main()
{

    cin >> n >> w;
    memset(dp , -1 , sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        cin >> weights[i];
        cin >> values[i];
    }
    cout << knapsack(1,0);
}
