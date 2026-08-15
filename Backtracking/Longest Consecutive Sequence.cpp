#include<bits/stdc++.h>
using namespace std;
int n;
unordered_map<int,int> freq;
int longestConsecutive(vector<int>& nums)
{
    n = nums.size();
    int mx = INT_MIN;
    int mn = INT_MAX;
    for(int i = 0 ; i < n ;i++)
    {
        freq[nums[i]]++;
        mx = max(mx,nums[i]);
        mn = min(mn,nums[i]);
    }
    int ans = 0 ;
    int count = 0;
    for(auto [k,v] : freq)
    {
        int x = k;
        // check if start of the sequence
        if(freq.find(x-1) == freq.end())
        {
            int i = 0;
            while(true)
            {
                if(freq.count(x+i) > 0)
                {
                    count++;
                    i++;
                }
                else
                {
                    ans = max(ans , count);
                    count = 0;
                    break;
                }
            }
        }
    }
    ans = max(count , ans);
    return ans;
}
int main()
{
    vector<int> nums = {0,3,7,2,5,8,4,6,0,9999999};
    cout << longestConsecutive(nums);
}