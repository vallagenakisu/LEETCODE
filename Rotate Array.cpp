#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    k = k % n;
    int it = n - k;
    for (int i = 0; i < it; i++)
    {
        nums.push_back(nums[i]);
    }
    nums.erase(nums.begin(), nums.begin() + it);
    // for (auto x : nums)
    //     cout << x << " ";
}
int main()
{
    vector<int> nums = {-1,-100,3,99};
    rotate(nums, 2);
}