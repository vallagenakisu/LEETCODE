#include<bits/stdc++.h>
using namespace std;

vector<int> memo;
int rob(vector<int>& nums)
{
    int n = nums.size();
    return max(helper(0,nums) , helper(1,nums));
}
int main()
{

}