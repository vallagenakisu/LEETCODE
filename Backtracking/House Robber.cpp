#include<bits/stdc++.h>
using namespace std;
int n;
const int N = 1e2+9;
int memo[N];
int f(int idx, vector<int> & nums)
{
    if(idx >= nums.size()) return 0;
    if(memo[idx] != -1) return memo[idx];
    return memo[idx] = max(nums[idx] + f(idx+2,nums) , f(idx+1,nums));
}
int rob(vector<int>& nums)
{
    n = nums.size();
    memset(memo,-1,sizeof(memo));
    return f(0,nums);
}
int main()
{
    vector<int> nums = {2,9,8,3,6};
    cout << rob(nums) << endl;
}