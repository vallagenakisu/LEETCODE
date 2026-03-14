#include <bits/stdc++.h>
using namespace std;
int search(vector<int> &nums, int target)
{
    int n = nums.size();
    int l = 0 , r = n - 1;
    while(l <= r)
    {
        int mid = l + (r-l)/2;
        if(nums[mid] == target )
        return mid;
        else if( nums[mid] > target )
        {
            r = mid - 1;
        } 
        else 
        {
            l = mid + 1;
        }
    } 
    return -1;
}
int main()
{
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 9 ;
    cout << search(nums, target);
}