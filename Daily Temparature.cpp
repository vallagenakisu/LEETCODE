#include <bits/stdc++.h>
using namespace std;
vector<int> dailyTemperatures(vector<int> &temperatures)
{
    int n = temperatures.size();
    stack<pair<int,int>> stk;
    int curr_max = temperatures[0];
    int curr_max_idx = 0;
    stk.push({0,temperatures[0]});
    vector<int> ans(n,0);
    for(int i = 1 ; i < n ; i++)
    {
        if(temperatures[i] <= stk.top().second)
        {
            stk.push({i,temperatures[i]});
        }
        else 
        {
            if(temperatures[i] > curr_max)
            {
                curr_max = temperatures[i];
                curr_max_idx = i;
            }
            while( !stk.empty() and stk.top().second < temperatures[i] )
            {
                // cout << "reached"<<endl;
                ans[stk.top().first] = i - stk.top().first;
                stk.pop();
            }
            stk.push({i , temperatures[i]});
        }
    }
    return ans;
}
int main()
{
    vector<int> temparatures = {30, 38, 30, 36, 35, 40, 28};
    auto ans = dailyTemperatures(temparatures);
    for(auto x : ans)
    cout << x <<" ";


}
