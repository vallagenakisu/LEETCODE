#include<bits/stdc++.h>
using namespace std;
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<int> suffix_max(n,0);
    int mx = INT_MIN;
    // 7 1 5 3 6 4 
    // 7 6 6 6 6 4
    for(int i = n - 1 ; i >= 0 ; i--)
    {
        mx = max(mx , prices[i]);
        suffix_max[i] =mx;
    }
    int ans = 0;
    for(int i = 0 ; i < n ; i++)
    {
        ans = max(ans , suffix_max[i] - prices[i]);
    }
    return  ans ;
}
// greedy 
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int cur_min = INT_MAX;
    int mx_profit = INT_MIN;
    // 7 1 5 3 6 4 
    for(int i = 0 ; i < n ; i++)
    {
        cur_min = min(cur_min , prices[i]);
        mx_profit = max(mx_profit , prices[i] - cur_min);
    }
    return mx_profit;
}

int main()
{
    vector<int> prices = {7,1,5,3,6,4};
    cout << maxProfit(prices);
}