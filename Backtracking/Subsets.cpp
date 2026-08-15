#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> boro_ans;
vector<int> choto_ans;

// void fun(vector<int> & nums , int i)
// {
//     if(i >= n)
//     {
//         boro_ans.push_back(choto_ans);
//         return ;
//     }
//     //take
//     choto_ans.push_back(nums[i]);
//     fun(nums,i+1);
//     //don't take
//     choto_ans.pop_back();
//     fun(nums,i+1);
// }
// alternative solution
void fun(vector<int> &nums, int start)
{
    boro_ans.push_back(choto_ans);
    for(int i = start ; i < nums.size(); i++)
    {
        choto_ans.push_back(nums[i]);
        fun(nums,i+1);
        choto_ans.pop_back();
    }
}
vector<vector<int>> subsets(vector<int>& nums)
{
    n = nums.size();
    fun(nums,0);
    for(auto x : boro_ans)
    {
        for(auto y : x)
        cout << y << " ";
        cout <<endl;
    }
    return boro_ans;
}

int main()
{
    vector<int> nums = {1,2,3};
    subsets(nums);
}