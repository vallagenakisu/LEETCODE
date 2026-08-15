#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    int n = intervals.size();
    int i = 0;
    vector<vector<int>> merged;
    while(i < n and intervals[i][1] < newInterval[0])
    {
        merged.push_back(intervals[i]);
        i++;
    }
    while(i < n and intervals[i][0] <= newInterval[1])
    {
        newInterval[0] = min( intervals[i][0], newInterval[0] );
        newInterval[1] = max( intervals[i][1], newInterval[1] );
        i++;
    }
    merged.push_back(newInterval);
    while(i<n)
    {
        merged.push_back(intervals[i]);
        i++;
    }
    for (auto x : merged)
    {
        for (auto y : x)
            cout << y << " ";
        cout << endl;
    }
    return merged;
}

int main()
{
    vector<vector<int>> intervals =
    {
        {1,5}   
    };
    vector<int> newInterval = {0,0};
    insert(intervals,newInterval);
}