#include<bits/stdc++.h>
using namespace std;
const int N = 109;
int weights [N] , values[N];
#define int long long 
int n , w;
int inf = 1e11 + 9;
int dp[N][N*1000];
int f(int i , int value)
{
    if(i == n+1 )
    {
        if(value == 0) return 0;
        return inf;
    }
    int &ans = dp[i][value];
    if(ans != -1) return ans;
    ans = inf;
    //take 
    ans = weights[i] + f(i+1 , value - values[i]);
    // dont take 
    ans = min( ans , f(i+1 , value));
    return ans;
}


int32_t main()
{
    cin >> n >> w;
    for(int i = 1; i <= n ; i++) cin >> weights[i] >> values[i];
    int ans = 0;
    memset(dp , -1 , sizeof(dp));
    for(int value = 1 ; value <= n*1000; value++)
    {
        if(f(1,value) <= w){
            ans = max(ans , value);
        }   
    }
    cout << ans << endl;
    
}