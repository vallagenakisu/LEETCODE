#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> boro_ans;
vector<int> choto_ans;
void fun(vector<int>& candidates ,int i ,int target,int sum)
{
    if(i == n)
    {
        if(sum == target)
        {
            boro_ans.push_back(choto_ans);
        }
        return;
    }

    if(sum >= target)
    {
        if(sum == target)
        {
            boro_ans.push_back(choto_ans);
        }
        return;
    }

    for(int j = i ; j < n ; j++)
    {
        if( j > i and candidates[j] == candidates[j-1]) continue;
        sum += candidates[j];
        choto_ans.push_back(candidates[j]);
        fun(candidates, j + 1 , target , sum);
        sum -= candidates[j];
        choto_ans.pop_back();
    }
    return;
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
{
    sort(candidates.begin() , candidates.end());
    n = candidates.size();
    fun(candidates,0,target,0);
    for(auto x : boro_ans)
    {
        for(auto y : x)
        cout << y << " ";
        cout << endl;
    }
    return boro_ans;
}

int32_t main()
{
    vector<int> candidates = {9,2,2,4,6,1,5};
    int target = 8;
    combinationSum2(candidates,target);
}