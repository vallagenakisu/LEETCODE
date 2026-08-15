#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string s)
{
    // if(s.size() == 1) return false;
    int l = 0;
    int r = s.size() - 1;
    while(l<r)
    {
        if(s[l] != s[r]) return false;
        l++;r--;
    }
    return true;
}
string longestPalindrome(string s)
{
    vector<pair<string,int>> anss; // string and length;
    int n = s.size();
    for (int i = 0; i < n; ++i)
    {
        for (int len = 1; len <= n - i; ++len)
        {
            string sub = s.substr(i, len);
            cout << sub << endl;
            if(isPalindrome(sub))
            {
                anss.push_back({sub,sub.size()});
            }
        }
    }
    int mx = INT_MIN;
    string ans= "";
    for(auto [s,l] : anss)
    {
        if(l > mx)
        {
            mx = l;
            ans = s;
        }
    }
    return ans;
}
void solve()
{
    string s = "ababd";
    cout << longestPalindrome(s);
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}