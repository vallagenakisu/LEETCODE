#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int n;
int dp[N][3];
vector<vector<int>> days(N, vector<int>(4, 0));
int f(int i, int selected)
{
    if(i == n+1 ) return 0;
    if(dp[i][selected] != -1) return dp[i][selected];
    vector<int> day = days[i];
    int ans = 0;
    for (int k = 1; k <= 3; k++)
    {
        if (selected != k)
        {

            ans= max(ans , day[k] + f(i + 1, k));
            
        }
    }
    dp[i][selected] = ans;
    
    return ans;
}
int main()
{
    cin >> n;
    memset(dp,-1,sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        vector<int> day(4, 0);
        for (int j = 1; j <= 3; j++)
        {
            cin >> day[j];
        }
        days[i] = day;
    }
    cout << f(1, -1);
}