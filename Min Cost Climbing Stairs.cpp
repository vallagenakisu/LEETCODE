#include<bits/stdc++.h>
using namespace std;
vector<int> memo;
int helper(int i,vector<int> &cost)
{
    if(i > cost.size() - 1 ) return 0;
    if(memo[i] != -1 ) return memo[i];
    memo[i] = cost[i] + min(helper(i+1,cost) , helper(i+2,cost));
    return memo[i];
}
int minCostClimbingStairs(vector<int>& cost)
{
    int n = cost.size();
    memo = vector<int> (n+1,-1);
    return min(helper(0,cost) , helper(1,cost));
}

int main()
{
    vector<int> cost = {1,2,3};
    cout << minCostClimbingStairs(cost); 
}