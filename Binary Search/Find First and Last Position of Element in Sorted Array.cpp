#include<bits/stdc++.h>
using namespace std;

int firstOccurrence(vector<int> & nums, int target)
{
    int size = nums.size();
    int l = 0, r = size - 1 ;
    int ans = -1 ;
    while( l<=r )
    {
        int mid = l + (r-l)/2 ;
        if(nums[mid] == target) {
            ans = mid;
            r = mid - 1;
        }
        else if(nums[mid] > target) r = mid - 1;
        else l = mid + 1;
    }

    return ans;
}
int lastOccurrence(vector<int> &nums, int target)
{
    int size = nums.size();
    int l = 0 , r = size - 1;
    int ans = -1 ;
    while(l<=r)
    {
        int mid = l + (r-l)/2;
        if(nums[mid] == target){
            ans = mid ;
            l = mid + 1;
        }
        else if(nums[mid] > target) r = mid - 1 ;
        else l = mid + 1 ;
    }
    return ans;
}

vector<int> searchRange(vector<int>& nums, int target) {
    int f = firstOccurrence(nums,target);
    int l = lastOccurrence(nums, target);
    vector<int> ans = {f,l};
    return ans;
}

int main()
{
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    auto ans = searchRange(nums,target);
    for(auto x : ans)
    cout << x << " ";

}