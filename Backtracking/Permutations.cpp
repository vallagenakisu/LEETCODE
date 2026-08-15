#include <bits/stdc++.h>
using namespace std;
vector<int> taken(10,0);
vector<int> result;
vector<vector<int>>results;
void backtrack(vector<int>&nums )
{
    if(result.size() == nums.size())
    {
        results.push_back(result);
    }
    for(int i = 0 ; i < nums.size() ; i++)
    {
        //check if taken
        if(!taken[i])
        {
            result.push_back(nums[i]);
            taken[i] = 1;
            backtrack(nums);
            taken[i] = 0;
            result.pop_back();
        }
    }
}

vector<vector<int>> permute(vector<int>& nums)
{
    backtrack(nums);
    for(auto x: results)
    {
        for(auto y : x)
        cout << y << " ";
        cout << endl;
    }
    return results;
}
int32_t main() {
    ios::sync_with_stdio(0);
    vector<int> nums = {1,2,3};
    permute(nums);
    
}