#include<bits/stdc++.h>
using namespace std;

// Naive Approach
// int maxProfit(vector<int> &prices)
// {
//     int size = prices.size();
//     vector<int> profits(size,0);
//     for(int i = 0 ; i < size ; i++)
//     {
//         for(int j = i +1 ; j < size ; j++)
//         {
//             if( prices[i] < prices[j])
//             {
//                 profits[i] = max(profits[i], prices[j] - prices[i]);
//             }
//         }
//     }
//     auto ans = max_element(profits.begin() , profits.end());
//     return *ans;
// }

// One Pass Approach

int maxProfit(vector<int> &prices)
{
    int size = prices.size();
    int left_min = INT_MAX;
    int max_profit = -1;
    for(int i = 0 ; i < size ; i++)
    {
        left_min = min(left_min , prices[i]);
        max_profit = max(max_profit , prices[i] - left_min);
    }
    return max_profit;
}


int main()
{
    vector<int> prices = {7,10, 1, 3, 6, 9, 2};
    cout << maxProfit(prices);
    

    
}