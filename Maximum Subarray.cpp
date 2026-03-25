#include <bits/stdc++.h>
using namespace std;
int maxSubArray(vector<int> &nums)
{
    int n = nums.size();
    if(n == 1 ) return nums[0];
    // -2 1 -3 4 -1 2 1 -5 4 
    int curr_sum = 0;
    int ans  = INT_MIN;
    for(int i = 0 ; i < n ; i++)
    {
        curr_sum = max(curr_sum + nums[i] , nums[i]);
        ans = max(ans , curr_sum);
    }
    return ans;
}
int main()
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(nums);
}