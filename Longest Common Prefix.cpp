#include <bits/stdc++.h>
using namespace std;
string longestCommonPrefix(vector<string>& strs) 
{
    int n = strs.size();
    string ans = "";
    int mn = INT_MAX;
    for(auto x : strs)
    {
        int s = x.size();
        mn = min(mn,s);
    }
    // cout << mn << endl;
    // 3 height of the array 
    // 3 width
    for(int i = 0 ; i < mn ; i++)
    {
        int j = 1;
        while(j < n)
        {
            if( strs[j-1][i] != strs[j][i] ) return ans;
            j++;
        }
        ans.push_back(strs[j-1][i]);
    }
    return ans;
}
int main()
{
    vector<string> strs = {"dog","racecar","car"};
    cout << longestCommonPrefix(strs);
}