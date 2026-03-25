#include<bits/stdc++.h>
using namespace std;

bool canJump(vector<int> &nums)
{
    int n = nums.size();
    int last_index = n - 1;
    if( n == 1 )
    {
        if( nums[0] == 0 or nums[0] == 1 ) return true;
    }
    for(int i = 0 ; i < n ; )
    {
        // cout << nums[i] << endl;
        if(nums[i] == 0 ) return false;
        i = i + nums[i];
        if( i >= last_index)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    vector<int> nums = {3,2,1,0,4};
    cout << canJump(nums);
}