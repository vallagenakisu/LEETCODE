#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const int N = 1e6+9;
int dp[N];
int f(int n )
{
    if (n <= 0) return 0;
    if(dp[n] != -1) return dp[n];
    vector<int> digits;
    int digit = n ;
    while(digit)
    {
        if(digit%10 !=0 )
        digits.push_back(digit%10);
        digit = digit / 10;
    }
    
    int ans = inf;
    for(auto x : digits)
    {
        ans = min(ans , 1 + f(n-x));
    }
    dp[n] = ans; 
    return dp[n];
}
int main()
{
    memset(dp,-1,sizeof(dp));
    int n ;
    cin >> n;
    cout << f(n);
}