#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int> &nums)
{
    queue<int> m_idx, q;
    int mx = INT_MIN ;
    for (int i = 0; i < nums.size(); i++)
    {
        // insert all the minus index
        if (nums[i] < 0)
        {
            m_idx.push(i);
            q.push(i);
        }
        mx = max(nums[i] , mx);
    }
    if(mx<= 0) return mx;
    // while (!q.empty())
    // {
    //     cout << q.front() << " ";
    //     q.pop();
    // }
    // cout << endl;
    int cur_mul = 1;
    int max_mul = cur_mul;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            cur_mul = 1;
        }
        else
        {
            if (!m_idx.empty() and i == m_idx.front())
            {
                m_idx.pop();
                if (!m_idx.empty() or cur_mul < 0)
                {
                    cur_mul = cur_mul * nums[i];
                }
                else
                    cur_mul = 1;
            }
            else
                cur_mul = cur_mul * nums[i];
        }
        cout << cur_mul << " ";
        max_mul = max(cur_mul, max_mul);
    }
    cout << endl;
    return max_mul;
}
int main()
{
    vector<int> nums = {0,2};
    cout << maxProduct(nums);
}