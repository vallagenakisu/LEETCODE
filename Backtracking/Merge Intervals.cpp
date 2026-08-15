#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    sort(intervals.begin(),intervals.end());
    vector<vector<int>> merged;
    for(auto &interval : intervals)
    {
        if(merged.empty() || merged.back()[1] < interval[0])
        {
            merged.push_back(interval);
        }
        else if(merged.back()[1] >= interval[0])
        {
            merged.back()[1] = max( merged.back()[1],interval[1]);
        }
    }
    for(auto x : merged)
    {
        for(auto y : x) cout << y <<" ";
        cout << endl;
    }
    return merged;
}
int main()
{
    vector<vector<int>> intervals =
    {
        {1,3},
        {2,6},
        {8,10},
        {15,18}
    };
    merge(intervals);
}