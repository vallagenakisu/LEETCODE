#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> boro_ans;
vector<int> choto_ans;
int n;
void fun(vector<int> & nums , int target , int i , int sum)
{
    if(i >= n) return;
    //base case 
    if(sum >= target)
    {
        if(sum == target)
        {
            boro_ans.push_back(choto_ans);
        }
        return ;
    }
    //take 
    sum += nums[i];
    choto_ans.push_back(nums[i]);
    fun(nums,target,i,sum);
    // take next
    choto_ans.pop_back();
    sum -= nums[i];
    if(i+1 < n)
    fun(nums,target,i+1,sum);
}
vector<vector<int>> combinationSum(vector<int>& nums, int target)
{
    n = nums.size();
    fun(nums,target,0,0);
    for(auto x : boro_ans)
    {
        for(auto y : x)
        cout << y <<" ";
        cout << endl;
    }
    return boro_ans;
}
int main()
{
    vector<int> nums = {3};
    int target = 5 ;
    combinationSum(nums,target);
}