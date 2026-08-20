#include<bits/stdc++.h>
using namespace std;

vector<int> memo;
int f(int i , int end, vector<int> &nums)
{
    if(i >= end) return 0;
    if(memo[i] != -1) return memo[i];
    //take 
    memo[i] = nums[i] + f(i+2,end,nums);
    //dont take
    memo[i] = max(memo[i],f(i+1,end,nums));
    return memo[i];
}
int rob(vector<int>& nums)
{
    int n = nums.size();
    memo = vector<int>(n,-1);
    int firstCall = f(0,n,nums);
    // memo.clear();
    memo = vector<int>(n,-1);
    int secondCall = f(1,n-1,nums);
    return max(firstCall,secondCall);
}
int main()
{
    vector<int> nums ={1,2,3,1};
    cout << rob(nums);

}