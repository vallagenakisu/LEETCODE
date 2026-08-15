#include<bits/stdc++.h>
using namespace std;
vector<int> memo;
int helper(int i, vector<int>& nums) {
    if (i >= nums.size()) return 0;
    if (memo[i] != -1) return memo[i];
    memo[i] = max(nums[i] + helper(i + 2, nums), helper(i + 1, nums));
    return memo[i];
}

int rob(vector<int>& nums) {
    int n = nums.size();
    memo = vector<int>(n, -1);
    return helper(0, nums);
}
int main()
{
    vector<int> nums = {1,1,3,3};
    cout << rob(nums);
}