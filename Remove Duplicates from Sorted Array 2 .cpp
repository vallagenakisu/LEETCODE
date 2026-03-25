#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 9;
vector<int> freq(N, 0);
int removeDuplicates(vector<int> &nums)
{
    int n = nums.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        freq[nums[i]]++;
    }
    nums.clear();
    for (int j = 0; j < N; j++)
    {
        if (freq[j] > 0)
        {
            if (freq[j] > 1)
            {
                for (int i = 0; i < 2; i++)
                {
                    ans++;
                    nums.push_back(j);
                }
            }
            else
            {
                ans++;
                nums.push_back(j);
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    cout << removeDuplicates(nums);
}