#include <bits/stdc++.h>
using namespace std;
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    // 7 1 5 3 6 4 
    int buy = prices[0];
    int profit = 0;
    for(int i = 1 ; i < n ; i++)
    {
        if( prices[i] < prices[i-1] )
        {
            int sell = prices[i-1] - buy;
            profit += sell;
            buy = prices[i];
        }
    }
    profit += prices[n-1] - buy;
    return profit;
}
int main()
{
    vector<int> prices = {7,1,5,3,6,4};
    cout << maxProfit(prices);
}