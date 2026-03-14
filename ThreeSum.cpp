#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums) {
    int len = nums.size();
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;
    for(int k = 0 ; k < len; k ++){
        if(k > 0 and nums[k] == nums[k-1]) continue;
        int l = k+1 ;
        int r = len-1;
        while( l < r ){
            int sum = nums[l] + nums[r] + nums[k];
            if(sum < 0  ){
                l++;
            }
            else if( sum > 0){
                r--;
            }
            else if(sum == 0){
                ans.push_back({nums[k] , nums[l] , nums[r]});
                l++;
                r--;
                while(l<r and nums[l] == nums[l-1]) l++;

            }
        }
    }
    return ans;
}

vector<vector<int>> threeSum(vector<int> &nums)
{
    int len = nums.size();
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;
    set<vector<int>> seen;
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            for (int k = j + 1; k < len; k++)
            {
                if(nums[i] + nums[j] + nums[k] == 0 )
                {
                    vector<int> triplet = {nums[i] , nums[j] , nums[k]};
                    if(seen.find(triplet) == seen.end())
                    {
                        seen.insert(triplet);
                        ans.push_back(triplet);
                    }
                }
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {-2, 0, 1, 1, 2};

    vector<vector<int>> a = threeSum(nums);
    for (auto x : a)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
}