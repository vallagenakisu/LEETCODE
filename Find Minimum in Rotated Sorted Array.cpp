#include<bits/stdc++.h>
using namespace std;
int findMin(vector<int> &nums)
{
    int n = nums.size();
    if( n==1 ) return nums[0];
    int l = 0 , r = n - 1;
    int ans = INT_MAX;
    while( l <= r )
    {
        if( l < 0 or r < 0) break;
        if( l > n or r > n) break;
        int mid = l + (r-l)/2;
        if( nums[l] <= nums[mid] and nums[l] <= nums[r] )
        {
            ans = min(ans , nums[l]);
            l = mid + 1;
        }
        else if(nums[l] <= nums[mid] and nums[l] > nums[r])
        {
            l = mid + 1;
        }
        else if( nums[r] > nums[mid])
        {
            ans = min(ans , nums[mid]);
            r = mid -1;
        }
    }
    return ans;
}
int main()
{
    vector<int> nums = {2,3,4};
    cout << findMin(nums);
}