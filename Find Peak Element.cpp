#include<bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> &nums)
{
    //if(nums.size() == 1) return 0;
    int l = 0 , r = nums.size() - 1;
    int peak = 0;
    while( l < r )
    {
        int mid = l + (r - l) / 2;
        if(nums[mid] <= nums[mid+1])
        {
            l = mid + 1;
        }
        else 
        {
            r = mid;
        }
    }
    return l;
}

int main()
{
    vector<int> nums = {1,2};
    cout << findPeakElement(nums);
}

